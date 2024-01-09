#include <iostream>
#include <vector>

std::vector<int> count(int n) {
    std::vector<int> dp(n+1);
    /*
    for (int i = 0; i <= n; ++i) {
        dp[i] = dp[i/2] + (i % 2);
    }
    */
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i >> 1] +(i & 1);
    }
    return dp;
}

int main() {
    int n;
    std::cin >> n;
    for (auto x: count(n)) std::cout << x << " ";
}

