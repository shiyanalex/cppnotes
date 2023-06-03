#include <iostream>
#include <vector>

// dependent names problem - X зависит от T

template <typename T>
struct S {
    using X = T;
};

template <>
struct S<int> {
    static int X;
};

int a = 2;

// если int то умножение, а если другое то создаем указатель а
template <typename T>
void f() {
    typename S<T>::X * a;
}

int main() {
    
    //f<int>();
    //f<double>();

}
