#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// wrong logic
void f(int n, std::vector<int>& vec) {
    std::set<int, std::greater<int>> ans;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        bool flag = true;

        int l = i;
        for (int j = 0; j < n - i; ++j) {
            if (vec[l] == vec[k]) ++k, ++l;
            else {
                flag = false;
                break;
            }
        }
        int s = 2*n-i;
        if (flag) {
            for (int p = 0; p < i; ++p) {
                if (vec[s] == vec[k]) ++k, ++s;
                else { 
                    flag = false;
                    break;
                }
            }
        }
        if (k == n && flag) ans.emplace(n - i);
    }
    for (auto x: ans) std::cout << x << ";";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n*2);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vec[i] = x;
        vec[2*n-i-1] = x;
    }
    for (auto x: vec) std::cout << x << " ";
    std::cout << "\n";
    f(n, vec);
}
