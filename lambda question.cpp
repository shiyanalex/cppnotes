#include <iostream>
#include <vector>

struct A {
    int x = 3;
    A() {};

    A(const A&) { std::cout << "A copy\n"; }

    A(A&&) { std::cout << "A move\n"; }
};

int main() {

    std::vector<int> v {2,5,4,8,5,7,1,3,9,15};
    A as;

    int mid = 4;

    /*
    std::sort(v.begin(), v.end(), [=, a = std::move(a)] (int x, int y) mutable {
        return std::abs(x - mid) < std::abs(y - mid);
        std::ignore = a;
    });
    */
    std::cout << v.size() << "\n";
    int count = 0;
    auto f = [&, a = std::move(as)](int x, int y) mutable {
        ++count;
        std::cout << "in lambda " << mid << "\n";
        return std::abs(x - mid) < std::abs(y - mid);
        //std::ignore = a;
    };

    std::cout << "count " << count << "\n";


    std::sort(v.begin(), v.end(), f);
    std::cout << "count " << count << "\n";

    for (int x: v) std::cout << x << " ";

}

