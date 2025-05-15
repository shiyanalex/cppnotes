#include <iostream>
#include <vector>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
    T* arr;
    size_t sz;
    size_t cap;
    [[no_unique_adress]] Allocator alloc;   //c++20
    
    using AllocTraits = std::allocator_traits<Allocator>;

public:
    //Vector(size_t count, const T& value): arr(reinterpret_cast<T*>(new uint8_t[count * sizeof(T)])), sz(count), cap(count) {
    Vector(size_t count, const T& value): alloc(), arr(AllocTraits::allocate(count)), sz(count), cap(count) {
        try {
            for (size_t i = 0; i < sz; ++i) {
                //arr[i] = value;           // WRONG! нельзя присваивать эл арр что то пока там нету инициализированных элементов
                //new (arr + i) T(value);   // placement new 
                //alloc.construct(arr+i, value);
                AllocTraits::construct(arr+i , value);
            } 
        } catch (...) {
            //delete[] reinterpret_cast<char*>(arr);
            alloc.deallocate(arr);
            throw;
        }
    } 
    Vector(size_t count, const T& value = T(), const Alloc& alloc = Alloc());

    // без отн искл
    Vector(T, Alloc)operator=(const Vector<T, Alloc>& other) {
        if (this == &other) return *this;

        other.T* newvec(other.sz, other.alloc);

        auto tmp = alloc;
        try {
            if (alloc != other.alloc && AllocTraits::propagate_on_container_copy_assignment::value)
                alloc = other.alloc; // тоже може быть исключение
        } catch (...) {
            alloc = tmp;
            throw;
        }
 
        size_t i = 0;
        try {
            for (; i < other.sz; ++i) {
                newvec.push_back(arr[i]);
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                AllocTraits::destroy(alloc, newvec + j);
            }
            AllocTraits::deallocate(newvec);
            alloc = tmp;
            throw;
        }

        // теперь можно спокойно освобождать память
        for (size_t i = 0; i < sz; ++i) {
            pop_back();
        }
        AllocTraits::deallocate(arr, cap);

        arr = newvec;
        sz = other.sz;
        cap = other.cap;
        
        return *this;
    }


    T& operator[](size_t i) {
        return arr[i];
    }

    T& at(size_t i) {
        if (i >= sz) throw std::out_of_range("out of range");
        return arr[i];
    }
    
    const T& operator[](size_t i) const {
        return arr[i];
    } 

    const T& at(size_t i) const {
        if (i >= sz) throw std::out_of_range("out");
        return arr[i];
    }
    
    size_t size() const {
        return sz;
    }
        
    void resize(size_t n, const T& value = T());

    size_t capacity() const {
        return cap;
    }
    
    //если заранее знаешь что будет не больше x числа эл, то проще сделать резерв 
    //вначале, чтобы потом не было реаллокации из за push_back
    // allocate -> construct -> destroy -> deallocate
    void reserve(size_t newcap) {
        if (newcap <= cap) return;
        
        //T* newarr = new T[n]; WRONG
        //T* newarr = reinterpret_cast <T*>(new uint8_t[n * sizeof(T)]); BAD but working
        //T* newarr = alloc.allocate(newcap);
        T* newarr = AllocTraits::allocate(alloc, newcap);

        /*
        try {
            std::uninitialized_copy(arr, arr + sz, newarr);
        } catch (...) {
            //delete[] reinterpret_cast<int8_t*>(newarr);
            //alloc.deallocate(newarr, newcap);
            throw;
        } */
        
        size_t i = 0; // выносим из цикла чтобы была безопастность отностительно искл (можно поменять местами)
        try {
            for (; i < sz; ++i) {
                //newarr[i] = arr[i]                // UB!! newarr dosnt have T in it, its raw bytes
                //new (newarr + i) T(arr[i])        // Placement new, но конструктор копирования может кинуть исключение
                //alloc.construct(arr + i, arr[i]);
                //AllocTraits::construct(alloc, newarr + i, arr[i]);
                AllocTraits::construct(alloc, newarr + i, std::move_if_noexcept(arr[i]));
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                //(newarr + j)->~T();
                //alloc.destroy(newarr + j);
                AllocTraits::destroy(alloc, newarr + j);
            }
            //delete[] reinterpret_cast<uint8_t*>(newarr);
            //alloc.deallocate(newarr, newcap);
            AllocTraits::deallocate(newarr);
            throw;
        }
        
        for (size_t i = 0; i < sz; ++i) {
            //(arr + i)->~T();
            //alloc.destroy(arr+i);
            AllocTraits::destroy(alloc, arr + i);        
        }

        //delete[] reinterpret_cast<char*>(arr);
        AllocTraits::deallocate(arr);
        arr = newarr;
        cap = newcap;
    }

    void push_back(const T& value) {
        /* if (sz >= cap) reserve(cap * 2);
        AllocTraits::construct(alloc, newarr + sz, value);
        //new (arr + sz) T(value);
        ++sz; */
        emplace_back(value);
    }
    void push_back(T&& value) {
        /* if (sz >= cap) reserve(cap * 2);
        AllocTraits::construct(alloc, newarr + sz, std::move(value));
        ++sz; */
        emplace_back(std::move(value));
    }
    
    // forward implementation 
    template<typename T>
    T&& forward(std::remove_reference_t<T>& x) noexcept {
        return static_cast<T&&>(x);
    }

    // forward<Args>(f(args)...)
    template<typename T>
    T&& forward(std::remove_reference_t<T>&& x) noexcept {
        return static_cast<T&&>(x);
    }

    template<typename T>                    // хотим мувнуть что мувается иначе не имеет смысла
    void emplace_back(Args&&... args) {     // perfect forwarding сам определяет r или l value args
        if (sz >= cap) reserve(cap * 2);
        AllocTraits::construct(alloc, arr + sz, std::forward<Args>(args)...);
        ++sz;
    }

    void pop_back() {
        //(arr + sz - 1)->~T();
        AllocTraits::destroy(alloc, arr + sz - 1);
        --sz;
    }

    struct iterator {
    private: 
        T* ptr;
    public: 
        T& operator*(){
            return *ptr;
        }
    };
};

/*
template<>
class Vector<bool> {    // std::_Bit_reference
private: 
    char* arr;
    size_t sz;
    size_t cap;

    struct BitReference {
        char* cell;
        uint8_t num;

        BitReference& operator=(bool b) {
            if (b) {
                *cell |= (1u << num);   //1u литеральный суффикс / беззнаковое число
            } else {
                *cell &= ~(1u << num);
            }
            return *this;
        }
        operator bool() const {
            return *cell & (1u << num);
        }
    };

public: 
    BitReference operator[](size_t index) {
        return BitReference{arr + index / 8, index % 8};
    }
}; */

//лайфхак чтобы узнать тип
template<typename U>
void f(const U&) = delete;

int main() { 

    std::vector<int> v;

    for (int i = 0; i < 25; i++) {
        v.push_back(i);
        std::cout << v.size() << " " << v.capacity() << "\n";
        
    }

    std::vector<bool> vb(10, false);

    vb[5] = true; // буль хранится в одном бите, что тогда представляет из себя обращение по идексу в вектор буль
    //f(vb[5]);



}
