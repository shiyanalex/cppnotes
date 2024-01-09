#include <iostream>
#include <vector>

int count(std::vector<int>& cost) {
    int n = cost.size();
    for(int i = 2; i < n; i++) {
        cost[i] += std::min(cost[i-1], cost[i-2]);
    }
    return std::min(cost[n-1], cost[n-2]);
}

int count2(std::vector<int>& cost) {
    int n = cost.size();
    std::vector<int> dp(n + 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    return dp[n];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    std::cout << count2(vec);
}
