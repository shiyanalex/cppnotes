#include <iostream>

// shared ptr - как юник только еще и копировать можно, указатель со счетчиком ссылок
// make_shared обладает одним недостатком, памать освобождается только после удаления weak_ptr

// Type erasure - базовая структура с виртуальным делитeром и методами и наследуемся от нее с шаблоном того что
// подменяем / создаем базовый полиморфный класс с виртуальными методами и от него делаем шаблонный наследник
template<typename T>
struct enable_shared_from_this {
private:
    std::weak_ptr<T> wptr;
public:
    std::shared_ptr<T> shared_from_this() const noexcept {
        return wptr.lock();
        // lock() Creates a new std::shared_ptr that shares ownership of the managed object.
    }
};

// из объекта структуры вернуть указатель на объект этой структуры
// нельзя создать shared_ptr из this потому если до этого уже существовал shared_ptr то будет вторая линейка и двойное удаление
// CRTP (Curiously recurring template pattern) - класс наследник другого шаблонного класса с шаблонным параметрам наш класс
// class Derived: public Base<Derived> - CRTP
class S: public enable_shared_from_this<S> {
public: 
    shared_ptr<S> get_this() {
        return shared_from_this();
    }
};

template<typename T>
class shared_ptr {
    
    struct BaseControlBlock {
        int* shared_count;
        int* weak_count;
        virtual void useDeleter(T* ptr) = 0;
        virtual ~BaseControlBlock() = default;
    };

    template<typename Deleter, typename Allocator>
    struct ControlBlock: BaseControlBlock {
        T* object;
        Deleter deleter;
        Allocator alloc;
        virtual void useDeleter(T* ptr) {
            deleter(ptr);
        }
    };

    template<typename Allocator>
    struct ControlBlockMakeShared: BaseControlBlock {
        Allocator alloc;
        T object;
    };

    T* ptr;
    BaseControlBlock* cb;

public:
    shared_ptr(T* ptr, Deleter deleter): cb(new ControlBlock<deleter>) {}

    shared_ptr(const shared_ptr& other) noexcept: ptr(other.ptr), shared_count(other.count) {
        ++*shared_count;
    }

    shared_ptr(shared_ptr&& other) noexcept: ptr(other.ptr), shared_count(other.count) {
        other.ptr = nullptr;
        other.shared_count = nullptr;
    }

    //TODO: assignment operators and if nullptr   
    
    ~shared_ptr() {
        --cb->shared_count;
        if (cb->shared_count == 0) {
            if (weak_count == 0) {
                cb->useDeleter(ptr);
            } else {
                if (ptr) delete prt;
                else static_cast<BaseControlBlock*>(cb)->object.~T();
            }
        }
    }
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args) {
    //void* p = ::operator new(sizeof(T) + sizeof(size_t)); не учтено выравнивание alignment?
    //new (p) T(std::forward<Args>(args)...);
    //auto cb = new typename shared_ptr<T>::ControlBlock(T(std::forward<Args>(args)..., 1)); аллокатор ???

    return shared_ptr<T>(cb);
}

template<typename T, typename Alloc, typename... Args>
shared_ptr<T> allocate_shared(const Alloc& alloc, Args&&... args) {
    using AllocControlBlock = typename std::allocator_traits<Alloc>::rebind_alloc<ControlBlockMakeShared<Alloc>>;
    AllocControlBlock newAlloc = alloc;
    cb(alloc);
}


// weak_ptr решает проблемму циклических ссылок (дерево родитель ребенок и указатель на дерево уже потеряли и оно должно уничтожиться)
// weak pointer не влияет на то будет ли уничтожен объект, с помощью него можно посмотреть жив ли он еще и получить на
// него shared
// смотрит на объект, проверяет жив ли он и с помощью него можно создать shared_ptr
// нельзя получить weak если нету shared 

template<typename T>
class weak_ptr() {

public: 
    weak_ptr(const shared_ptr<T>& other);
    bool expired() cosnt noexcept {
        ///???
    };// проверка уничтожен ли объект или нет
    shared_ptr<T> lock() const noexcept; // позволяет получить shared_ptr
    // что он хранит и как он проверят уничтожен ли объект
    ~weak_ptr() {
        if 
        // проверить правда ли мы последний и если нету shared_ptr тогда освобождаем память из под объектов
    };
};

int main () {

    shared_ptr<int> sp = std::make_shared<int>(5);
    auto p = std::make_shared<int>(5);

}
