#include <iostream>
#include <functional>
#include <functional>


// function позволяет хранить любой callable object
struct MyCompare {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

bool another_compare(int a, int b) {
    return a == b;
}

struct S {
    int x = 0;
    void print (int y = 1) {
        std::cout << "printing " << x + y << "\n";
    }
};

// Idea of implementation
// TODO move, pointers to member
template <typename... Args>
class function;

template <typename Ret, typename... Args>
class function<Ret(Args...)> {
    
    struct Base {
        virtual Ret operator()(Args...) = 0;
        virtual ~Base() = default;
        virtual Base* getCopy() const = 0;
        //virtual Base* getmove()
    };

    template <typename Functor>
    struct Derived: public Base {
        Functor functor;

        virtual Ret operator()(Args... args) override {
            return std::invoke(functor, std::forward<Args>(args)...);
            //return functor(std::forward<Args>(args)...);
        } 
        /*
        virtual Ret operator()(Head head, Tail tail) override {
            if constexpr (std::is_member_function_pointer_v<Functor>) {
                return (std::forward<Head>(head).*functor)(std::forward<Tail>(tail)...);
            } else {
                return functor(std::forward<Args>(args)...);
            }
        } */

        virtual Base* getCopy() const override {
            //return typeid(functor);
            return new Derived<Functor>(functor);
        }
        
        Derived(const Functor& functor): functor(functor){}
    };

    Base* fptr = nullptr;

public:

    template <typename F>
    function(const F& f): fptr(new Derived<F>(f)) {}

    ~function() {
        delete fptr;
    }

    Ret operator()(Args... args) const {
        return fptr->operator()(std::forward<Args>(args)...);
    }

    function& operator=(const function& other) {
        delete fptr;
        fptr = other.fptr->getCopy();
        return *this;
    }

    /*
    function& operator=(const function&& other) {
        fptr = std::move(other->fptr);
    } */
};

int main() {

    function<bool(int, int)> f = [](int a, int b) {
        return a < b;
    };

    /*
    f = [](int a, int b) {
        return a < b;
    }; */
    std::cout << f(1,2) << "\n";

    
    f = MyCompare();
    std::cout << f(1,2) << "\n";

    /*
    // & можно и не писать из за неявной конверсии
    f = another_compare;
    std::cout << f(1,2) << "\n\n";

    // указатель на метод
    void (S::*pm)(int) = &S::print;
    S s{5}; // s.x = 5
    (s.*pm)(3); // = 8

    std::function<void(S&, int)> f2 = pm;
    f2(s, 5);
    */
}

