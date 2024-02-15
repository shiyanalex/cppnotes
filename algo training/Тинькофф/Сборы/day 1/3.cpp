#include <iostream>
#include <vector>
int n;

// O(n^2)
std::vector<int> run(std::vector<int>& vec) {
    std::vector<int> ans(n);
    for (int i = 0; i < vec.size(); ++i) {
        ans[i] = vec[i];
        if (vec[i] <= i) {
            for (int j = 0; j < i; ++j) {
                if (ans[j] >= vec[i]) ++ans[j];
            }
        }
        //for (auto x: ans) std::cout << x << " ";
        //std::cout << "\n";
    }
    return ans;
}

// идем справа и смотрим сколько эл-ов справа больше или = нашему
// не работает
std::vector<int> run2(std::vector<int>& vec) {
    std::vector<int> ans(n);
    for (int i = n-1; i >= 0; --i) {
        int count = 0;
        for (int j = i+1; j < n; ++j) {
            if (vec[i] >= vec[j]) ++count;
        }
        //std::cout << count << " ";
        ans[i] = vec[i] + count;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    for (auto x: run2(vec)) std::cout << x << " ";
}
