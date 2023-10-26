#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    long n,s;
    std::cin >> n >> s;

    std::vector<long> vec;
    for (long i = 0; i < n; ++i) {
        long x;
        std::cin >> x;
        vec.push_back(x);
    }

    std::sort(vec.begin(), vec.end());

    long res = 0;
    for (auto x: vec) {
        if (s > x) res = x;
        else break;
    }
    std::cout << res;
}
