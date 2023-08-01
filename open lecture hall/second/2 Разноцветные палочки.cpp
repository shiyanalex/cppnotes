#include <iostream>
#include <set>

int main() {
    
    std::string s;
    std::cin >> s;

    std::set<std::string> sticks;

    /*
    for (int i = 0; i < 10; ++i) {
        sticks.insert("a");
        std::cout << i;
    } */
    sticks.insert("a");
    sticks.insert("b");
    sticks.insert("c");


    for (auto x : sticks) std::cout << x;
    std::cout << sticks[1];
}
