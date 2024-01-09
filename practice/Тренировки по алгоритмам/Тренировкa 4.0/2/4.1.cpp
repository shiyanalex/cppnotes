#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

std::set<int, std::greater<int>> zfunc(std::vector<int>& s) {
    std::vector<int> z(s.size(), 0);
    std::set<int, std::greater<int>> ans;
    z[0] = s.size();
    int l = 0;
    int r = 0;
	for (int i = 1; i < s.size(); ++i) {
        z[i] = std::max(0, std::min(r - i, z[i - l]));

        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
        if (z[i] == s.size() - i && z[i] % 2 == 0) {
            ans.emplace(z[i]/2);
        }
    }
    ans.emplace(0);
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n * 2 + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vec[i] = x;
        vec[2 * n - i] = x;
    }
    for (auto x: zfunc(vec)) std::cout << n - x << " ";
}

