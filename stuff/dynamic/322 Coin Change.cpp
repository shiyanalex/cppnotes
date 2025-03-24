#include <iostream>
#include <vector>
// DP bottom up
// Return the fewest number of coins that you need to make up that amount, else return -1.

int coinChange(int need, std::vector<int> vec) {
    std::vector<int> dp(need+1, INT_MAX-1); // MAX-1 because int overflow makes it nagative and min funciton breaks
    dp[0] = 0;
    
    for (int i = 1; i <= need; ++i) {
        for (auto x: vec) {
            if (i - x >= 0) dp[i] = std::min(dp[i], 1 + dp[i-x]);
        }
    }
    if (dp[need] < INT_MAX-1) return dp[need];
    else return -1;
}

int main() {
    std::vector<int> vec{1,2,5};
    std::cout << coinChange(11, vec);
}
