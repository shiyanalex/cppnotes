#include<iostream>

template<int N, int M>
constexpr int sum() {return N + M; }

int main() {

    std::cout << sum<2,5>();
    int x = 1;
    std::cout << sum<x,4>();
}
