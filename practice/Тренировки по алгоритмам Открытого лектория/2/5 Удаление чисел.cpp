#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) std::cin >> vec[i];

    std::unordered_map<int, int> mapper;

    for (int x : vec) ++mapper[x];

    int mx = 0;
    for (auto i : vec) {
        mx = std::max({mx, mapper[i] + mapper[i+1], mapper[i-1] + mapper[i]});
    }

    std::cout << n - mx;
}
