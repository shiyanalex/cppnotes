#include <iostream>

template <typename T>
T abs(T x) { return x > 0 ? x : -x; }

template <typename T>
T abs(T x, T y) { return x > 0 ? x : -x; }

struct Complex {
    int re;
    int im;
};

int main() {

    std::cout << abs(-6) << "\n";
    Complex c{2,4};

    std::cout << c.re << c.im;
    std::cout << abs(c);

}
