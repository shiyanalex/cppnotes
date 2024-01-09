#include <iostream>
#include <vector>

// DP bottom up
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by
// any combination of the coins, return -1.

int coinChange(std::vector<int>& vec, int need) {
    std::vector<int> dp(need+1, INT_MAX-1);
    dp[0] = 0;
    
    for (int i = 1; i <= need; ++i) {
        for (auto& x: vec) {
            if (i - x >= 0) dp[i] = std::min(dp[i], 1 + dp[i-x]);
        }
    }
    if (dp[need] != INT_MAX) return dp[need];
    else return -1;
}

int main() {
    std::vector<int> vec{1,2,5};
    std::cout << coinChange(vec, 11);
}
