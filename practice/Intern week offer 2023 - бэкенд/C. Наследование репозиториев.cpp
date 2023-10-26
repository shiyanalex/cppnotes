#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    //for (auto x : vec) std::cout << x << " ";
    int max = *std::max_element(vec.begin(), vec.end());
    std::cout << std::max(max, n);
}
