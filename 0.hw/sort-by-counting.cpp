#include <iostream>
#include <vector>

std::vector<int> sort(std::vector<int> vec) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (auto& x: vec) {
        min = std::min(min, x);
        max = std::max(max, x);
    }

    int k = max - min + 1;

    std::vector<int> res(k, 0);

    for (auto& x: vec) {
        ++res[x];
    }
    return res;
}

int main() {

    std::vector<int> v {1,5,2,6,7,3,6,2,9,2,1,1,5,7,3};

    for (auto& x: v) std::cout << x << " ";
    std::cout << "\n";
    for (int i = 0; i < 10; ++i) std::cout << i << " ";
    std::cout << "\n";
    for (auto& x: sort(v)) std::cout << x << " ";
}
