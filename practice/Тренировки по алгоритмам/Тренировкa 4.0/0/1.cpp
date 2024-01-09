#include <iostream>
#include <vector>
// https://contest.yandex.ru/contest/53027/problems/

void solve(std::vector<int>& vec, int a, int b) {
    int min = *std::min_element(vec.begin()+a, vec.begin()+b+1);
    bool flag = true;
    for (int i = a; i <= b; ++i) {
        if (vec[i] != min && flag) {
            std::cout << vec[i] << "\n";
            flag = false;
        }
    }
    if (flag) std::cout << "NOT FOUND\n";
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        int min = *std::min_element(vec.begin()+a, vec.begin()+b+1);
        int max = *std::max_element(vec.begin()+a, vec.begin()+b+1);
        if (min != max) std::cout << max << "\n";
        else std::cout << "NOT FOUND\n";
    }
}
