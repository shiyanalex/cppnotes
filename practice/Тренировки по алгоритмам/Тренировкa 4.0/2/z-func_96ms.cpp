#include <iostream>
#include <vector>

// cout in void and this gives the same result 96ms 
std::vector<int> calculateZFunction(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    int left = 0;
    int right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right) {
            z[i] = std::min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::string input;
    std::cin >> input;
    for (auto x: calculateZFunction(input)) std::cout << x << " ";
}

