#include <iostream>
#include <vector>
#include <string>

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

std::string arrayToString(const std::vector<int>& nums) {
    std::string result;
    for (int num : nums) {
        result += std::to_string(num) + " ";
    }
    result.pop_back();
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::string input;
    std::cin >> input;
    std::vector<int> z = calculateZFunction(input);
    std::cout << arrayToString(z) << std::endl;
}

