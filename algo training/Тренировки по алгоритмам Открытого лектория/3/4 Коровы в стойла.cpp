#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool good(int m, int k, std::vector<int> vec) {

    int cnt = 1;
    int prev = vec[0];

    for (auto& x : vec) {
        if (x - prev >= m) ++cnt, prev = x;
    }
    return cnt>=k;
}

int main() {

    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    
    int l = 0;
    int r = 1000000000;

    while (l < r) {
        long m = (l+r+1)/2;

        if (good(m, k, vec)) l = m;
        else r = m-1;
    }

    std::cout << l << "\n";

}

