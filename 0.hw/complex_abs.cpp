#include <iostream>
#include <cmath>

template <typename T>
T abs(T x) { return x > 0 ? x : -x; }

template <typename T>
struct Complex {
    T re;
    T im;
};

template <typename T>
auto abs(Complex<T> c){ return std::sqrt(c.re * c.re + c.im * c.im);}

int main() {

    std::cout << abs(-6) << "\n";

    Complex<int> comp{2,4}; // это оказывается агрегатная инициализация
    Complex<double> comp2{2.32,4.15};

    std::cout << comp.re <<  " " << comp.im << "\n";
    std::cout << comp2.re << " " << comp2.im << "\n";

    std::cout << abs(comp) << "\n";
    std::cout << abs(comp2) << "\n";

}
