#include <iostream> 
//#include <memory>

template<typename T>
struct default_delete {
    void operator()(T* ptr) const {
        delete ptr;
    }
};

template<typename T, typename Deleter = std::default_delete<T>>
class unique_ptr: private Deleter { // empty base optimization
    T* ptr;

public:
    unique_ptr(T* ptr): ptr(ptr) {}

    // копировать нельзя, но у нас же появился мув!!
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& other) noexcept: ptr(other.ptr) {
          other.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) {
        unique_ptr copy = std::move(other);
        swap(ptr, copy.ptr);
        return *this;
    }

    ~unique_ptr() {
        Deleter()(ptr);
    }
};

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {

    auto p = std::unique_ptr<int>(new int(5));

    unique_ptr<int> p2 = make_unique<int>(42);

    std::cout << sizeof(p) << "\n" << sizeof(p2);

}
