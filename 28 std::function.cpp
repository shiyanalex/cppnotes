#include <iostream>
#include <vector>
#include <functional>

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
        std::cout << "\nprinting " << x + y << "\n";
    }
};

int main() {

    std::function< bool(int, int) > f;

    f = [] (int a, int b) {
        return a < b;
    };
    std::cout << f(1,2);

    f = MyCompare();
    std::cout << f(1,2);

    // & можно и не писать из за неявной конверсии
    f = another_compare;
    std::cout << f(1,2);

    // указатель на метод
    void (S::*pm)(int) = &S::print;
    S s{5};
    (s.*pm)(3);

    std::function<  void(S&, int) > f2 = pm;
    f2(s, 4);

}


