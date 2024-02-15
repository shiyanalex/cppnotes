#include <iostream>

// Зачем менять дефолтный аллокатор? - например чтобы сделать лист/мап на стеке
// Container -> AllocTraits -> Allocator -> new (C++) -> malloc (C) -> OS kernel

// Аллокатор это просто примитивная обертка над new 
template<typename T>
struct Allocator {

    T* allocate(size_t n) {
        //return reinterpret_cast<T*>(new char[n * sizeof(T)]);
        return ::operator new(n * sizeof(T));
    }
    
    void deallocate(T* ptr, size_t n) {
        //delete[] reinterpret_cast<char*>(ptr);
        ::operator delete(ptr);
    }
    
    template<typename... Args>
    void construct(T* ptr, const Args&... args) {
        new(ptr) T(args...);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }

    template<typename U>
    struct rebind {
        using other = Allocator<U>;
    };

    template<typename U>
    Allocator(const Allocator<U>&) {}

    template<typename U>
    Allocator& operator=(const Allocator<U>&) {
        return *this;
    }
};

// PoolAllocator
// TODO copy support 
template<typename X>
struct PoolAllocator {
private:
    std::shared_ptr<Pool> pool;
    class Pool { 
        char* memory;
    };
public: 
    PoolAllocator() {}
    
    void deallocate(X* ptr, size_t n) {
        std::ignore = ptr;
    }

    ~PoolAllocator() {
       
    }
    template<typename U>
    struct rebind {
        using other = Allocator<U>;
    };
};

// Stack allocator - на стеке (мы уверены что все поместиться)
// Polymorphic allocator - 

// можно проинициализировать аллокатор копией, а можно новой другого типа, для этого в реализации самого аллокатора придумали завести метод
// select on container copy construction - который определяет что должен делать контейнер когда копируется аллокатор
// в зависимости от аллокатора, vector при копировании себя либо копировал аллокатор либо создавал новый (новый пул)

// аллокаторы равны если то что выделено одним, можно освободить другим

template<typename T, typename U = int(T::*)>
auto hmc_helper(int);

template<typename T>
false_type hmc_helper(...);

template<typename T, template... Args>
struct has_method_construct: decltype(hmc_helper<T, Args...>(0)) {};

// Allocator Traits
template<typename Alloc>
struct allocator_traits {

    template<typename... Args>
    // если ф принимает T&& где T шаблонный параметр, то эта ссылка не считается rvalue / это особая forwarding
    // reference
    static void construct(Alloc& alloc, typename Alloc::value_type* ptr, Args&&... args) {
        //constexpr - проверям до компиляции
        if constexpr (/*Alloc has method construct(Args...) metafunction*/) {
            alloc.construct(ptr, std::forward<Args>(args)...);
        } else {
            new (ptr) typename Alloc::value_type(std::forward<Args>(args)...);
        }
    }
};


int main() {
    char arr[10'000];
    stack_allocator<int> alloc(arr);
    std::vector<int, stack_allocator<int>> v(alloc);

}
