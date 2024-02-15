#include <iostream>
#include <vector>

int get_second_points_sum(std::vector<int>& first_points) {
    std::vector<int> prefix_sums;
    for (int point : first_points) {
        if (point == 0) {
            continue;
        }
        if (prefix_sums.size() == 0) {
            prefix_sums.push_back(point);
        } else {
            prefix_sums.push_back(prefix_sums.back() + point);
        }
    }
    int res = 0;
    int ind = 0;
    for (int point : first_points) {
        if (point == 0) {
            continue;
        }
        res += point * point;
        res += prefix_sums[std::min(ind + point, (int)prefix_sums.size() - 1)] - prefix_sums[ind];
        ind += 1;
    }
    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    if (n == 0) return 0;
    std::vector<int> first_points(m);
    for (int i = 0; i < m; i++) {
        std::cin >> first_points[i];
    }
    std::cout << get_second_points_sum(first_points);
    return 0;
}
