#include <iostream>
#include <vector>

int run(std::vector<std::vector<int>>& grid) {
    int res = 0;
    int n = grid.size();
    int m = grid[0].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int i = 1; i < m; ++i) dp[0][i] = dp[0][i-1] + grid[0][i];
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    */
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[n-1][m-1];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> grid[i][j];
        }
    }
    /*
    for (auto x: grid) {
        for (auto y: x) { 
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    */
    std::cout << run(grid);
}
