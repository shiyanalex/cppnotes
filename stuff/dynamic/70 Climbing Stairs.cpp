#include <iostream>
#include <vector>
/*
There are n stairs, a person standing at the bottom wants to climb stairs to reach the nth stair.
The person can climb either 1 stair or 2 stairs at a time, 
the task is to count the number of ways that a person can reach at the top.
*/

int count(int n) {
    std::vector<int> dp(n+1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    int n;
    std::cin >> n;
    std::cout << count(n);
}
