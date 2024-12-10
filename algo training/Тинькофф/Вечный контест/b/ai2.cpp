#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<pair<int, int>> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        int dist = abs(friends[i].first - friends[i - 1].first);
        if (dist + friends[i].second <= T) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
