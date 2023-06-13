#include<iostream>
#include<vector>
//#include<cstdlib>

// new / delete overloading 

void* operator new(size_t n) {
    std::cout << "allocating " << n << "\n";
    void* ptr = std::malloc(n);
    if (!ptr) 
        throw std::bad_alloc();
    return ptr;
}

void operator delete(void* ptr) noexcept {
    std::cout << "deallocating " << ptr << "\n";
    std::free(ptr);
}

void* operator new(size_t n, const std::nothrow_t&) noexcept {
    std::cout << "allocating " << n << " bytes nothrow\n";
    void* ptr = std::malloc(n);
    return ptr;
}

/* I guess you cant overwrite placement new
void* operator new(size_t n, void* ptr) noexcept {
    std::cout << "allocating " << n << "bytes placement new\n";
    return ptr;
} */

struct S {
    static void* operator new(size_t n) {
        std::cout << "allocating " << n << " bytes for structure S\n";
        void* ptr = std::malloc(n);
        if (!ptr) 
            throw std::bad_alloc();
        return ptr;
    }

    static void operator delete(void* ptr) noexcept {
        std::cout << "deallocating S\n";
        std::free(ptr);
    }
};

int main() {

    S* s = new S();

    int* p = new(std::nothrow) int(5);
    delete p;

    std::vector<S> v(5);
    for (int i = 6; i < 100; ++i) {
        v.push_back(S());
    }

}
