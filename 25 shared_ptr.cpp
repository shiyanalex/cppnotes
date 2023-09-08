#include <iostream>

// shared ptr - как юник только еще и копировать можно, указатель со счетчиком ссылок

// Type erasure
template<typename T>
class enable_shared_from_this {
    std::weak_ptr<T> wp;

    std::shared_ptr<T> shared_from_this() const {
        return wp.lock();
    }
};

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

    template<typename Deleter>
    struct ControlBlockRegular: BaseControlBlock {
        T* object;
        Deleter deleter;
        virtual void useDeleter() {
            deleter(ptr);
        }
    };

    //template<typename Allocator>
    struct ControlBlockMakeShared: BaseControlBlock {
        T object;
    };

    T* ptr;
    BaseControlBlock* cb;

public:
    shared_ptr(T* ptr, Deleter deleter): cb(new ControlBlockRegular<deleter>) {}

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
                else static_cast<ControlBlock*>(cb)->object.~T();
            }
        }
    }
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args) {
    //void* p = ::operator new(sizeof(T) + sizeof(size_t)); не учтено выравнивание alignment?
    //new (p) T(std::forward<Args>(args)...);
    auto cb = new typename shared_ptr<T>::ControlBlock(T(std::forward<Args>(args)..., 1));
    return shared_ptr<T>(cb);
}

template<typename T, typename Alloc, typename... Args>
shared_ptr<T> allocate_shared(const Alloc& alloc, Args&&... args) {
    using AllocControlBlock = std::allocator_traits<Alloc>::rebind_alloc<ControlBlockMakeShared<Alloc>>;
    AllocControlBlock newAlloc = alloc;
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
    ~weak_ptr();
};

int main () {

    shared_ptr<int> sp = std::make_shared<int>(5);
    auto p = std::make_shared<int>(5);


}
