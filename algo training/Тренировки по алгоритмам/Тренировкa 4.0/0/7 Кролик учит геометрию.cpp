#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int map[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    int dp[n][m];
    //можно заполнить 0 и смотреть dp[n-1][m-1], а можно макс закостылить и похуй
    for (int i = 0; i < n; ++i) dp[i][0] = map[i][0];
    for (int j = 0; j < m; ++j) dp[0][j] = map[0][j];
    int max = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (map[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                max = std::max(max, dp[i][j]);
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << max;
}

