#include <iostream>
#include <vector>

template<typename T>
int foo() {
    if constexpr (std::is_same_v<T, int>) {
        return 12;
    } else if constexpr (std::is_same_v<T, float>) {
        return 42;
    } 
    /* will work on C++23
    else {
        static_assert(false, "T should be int or float");
    } */
    else {
        std::cout << "T should be int or float";
    }
}

int main() {

    int smt = foo<double>();
    std::cout << smt;

}
