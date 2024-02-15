#include <iostream>
#include <unordered_map>

int main() {

    int n;
    std::cin >> n;

    std::unordered_map<long, int> mapper;
    for (int i = 0; i < n; ++i) {
        long x;
        std::cin >> x;
        ++mapper[x];
    }

    for (auto& x : mapper) if (x.second > n/2) std::cout << x.first;
}
