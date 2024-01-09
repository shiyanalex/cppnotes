#include <iostream>
#include <vector>

// O(n^2)
std::vector<int> run(std::vector<int>& vec) {
    std::vector<int> ans(vec.size());
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans.size(); ++j) {
            ans[i] += std::abs(vec[j] - vec[i]);
        }
    }
    return ans;
}

// O(n)
std::vector<int> run2(std::vector<int>& vec) {
    std::vector<int> ans(vec.size());
    std::vector<int> dp(vec.size());
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans.size(); ++j) {
            ans[i] += std::abs(vec[j] - vec[i]);
        }
    }
    return ans;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    for (auto x: run(vec)) std::cout << x << " ";
}
