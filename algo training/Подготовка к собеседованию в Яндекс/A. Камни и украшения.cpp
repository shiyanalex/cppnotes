#include <iostream>
#include <vector>

// https://contest.yandex.ru/contest/8458/problems/

int main() {
    std::string s1;
    std::cin >> s1;
    std::string s2;
    std::cin >> s2;

    int count = 0;
    for (int i = 0; i < s2.length(); ++i) {
        if (s1.find(s2[i]) != std::string::npos) ++count;
    }
    std::cout << count;
}
    /*  
    std::string j, s;
    std::cin >> j >> s;

    int result = 0;
    for (const char ch : s) {
        result += j.find(ch) != std::string::npos;
    }
    */

