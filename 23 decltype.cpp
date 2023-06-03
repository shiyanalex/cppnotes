#include<iostream>
#include<vector>

// Auto - понятно 
// Decltype - в компайл тайме определить тип выражения
// Class template argument deduction C++17 aka CTAD

template<typename Container>
decltype(auto) getByIndex(Container& cont, size_t index) {
    std::cout << "something\n"; 
    return cont[index];
}

int main() {

    std::vector v = {1,2,3,4,5}; 
    // getByIndex(v, 1) = 0;
    for (auto x : v) std::cout << x;
    // auto [key, value] 
    std::vector vv(v.begin(), v.end());
    decltype 
}
