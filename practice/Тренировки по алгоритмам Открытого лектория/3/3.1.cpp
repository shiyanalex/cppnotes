#include <iostream>
#include <vector>

std::pair<int, std::vector<int>> solve(int n, int k, std::vector<int>& arr) {
    auto can_build = [&](int m) {
        int res_count = 0;
        for (int i = 0; i < k; i++) {
            res_count += arr[i] / m;
            if (res_count >= n) {
                return true;
            }
        }
        return false;
    };

    int l = 0;
    int r = 2000000000;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (can_build(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    int res_count = l;
    std::vector<int> res_colors;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < arr[i] / res_count; j++) {
            res_colors.push_back(i + 1);
            if (res_colors.size() >= n) {
                break;
            }
        }
        if (res_colors.size() >= n) {
            break;
        }
    }
    return {res_count, std::vector<int>(res_colors.begin(), res_colors.begin() + n)};
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        std::cin >> arr[i];
    }
    auto [res_count, res] = solve(n, k, arr);
    std::cout << res_count << std::endl;
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
