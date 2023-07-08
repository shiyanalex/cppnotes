#include <iostream>
#include <vector>
#include <map>
// & functional programming
// closure types - то что лямбда генерирует

struct A {
    int a = 0;
    
    A() {};

    A(const A&) { std::cout << "A copy\n"; }
    
    A(A&&) { std::cout << "A move\n"; }

    void method() {
        auto f = [a](int x, int y) mutable {
            ++a; 
            return std::abs(x - a) < std::abs(y - a);
        };
    }
};

int main() {

    std::vector v {1,5,3,2,4,6,0,8};
    A a;

    std::cout << a.x;

    int mid = 5;

    /*
    std::sort(v.begin(), v.end(), [&mid](int x, int y) {
            return std::abs(x - mid) < std::abs(y - mid);
        });
    */

    // mutable - можно локальные данные изменять
    auto f = [mid](int x, int y) mutable {
        ++mid;
        std::cout << "mid = " << mid <<"\n";
        return std::abs(x - mid) < std::abs(y - mid);
    };



    // immediate invocation
    // [](){}();
    // чтобы проверить много сложных условий

    int x;
    std::cin >> x;
    const int c = [](int a) {
        if (a > 0) return 2;
        if (a > 3) return 1;
        else return 0;
    }(x);

    // захват с инициализацией c++14
    // [m = mid + 1]
 
    auto ff = [mid, a = std::move(a)](int x, int y) mutable -> bool {
        ++mid;
        return std::abs(x - mid) < std::abs(y - mid);
    }; 

    // capture with const &
    auto g = [&mid = std::as_const(mid)](){};

    // std::map<int, std::string, decltype(f)> m;

    std::sort(v.begin(), v.end(), ff);
    for (int x : v) std::cout << x;

}
