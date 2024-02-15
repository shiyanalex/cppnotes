#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// https://contest.yandex.ru/contest/53029/problems/

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& v: vec) std::cin >> v;
    int x;
    std::cin >> x;

    int less = 0;
    for (auto& v: vec) if (v < x) ++less;
    std::cout << less << "\n" << vec.size()-less;
}
