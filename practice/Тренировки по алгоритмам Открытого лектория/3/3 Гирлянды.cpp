#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

bool good(long m, long n, std::vector<long> vec) {
    long max = 0;

    for (auto& x : vec) {
        max += x/m;
    }
    return max >= n;
}

int main() {

    int n, k;
    std::cin >> n >> k;

    std::vector<long> vec(k);

    for (auto& x : vec) std::cin >> x;
    
    long l = 0;
    long r = 2 * pow(10, 9);

    // right-hand binary search
    while (l < r) {
        long m = (l+r+1)/2;

        if (good(m, n, k, vec)) l = m;
        else r = m-1;
    }

    std::cout << l << "\n";

    int res_count = l;
    std::vector<int> res_colors;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < vec[i] / res_count; j++) {
            res_colors.push_back(i + 1);
        }
        if (res_colors.size() >= n) {
            break;
        }
    }
    for (auto x: res_colors) std::cout << x << "\n";
}

