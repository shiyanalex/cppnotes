#include <iostream>
#include <vector>

int lengthOfLCS(std::string v1, std::string& v2) {
    int n = v1.size();
    int m = v2.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v1[i-1] == v2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

std::string lcs(std::string v1, std::string& v2) {
    int n = v1.size();
    int m = v2.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v1[i-1] == v2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    */

    std::string ans = "";
    while (dp[n][m] != 0) {
        if (v1[n-1] == v2[m-1]) {
            ans += v1[n-1];
            --n, --m;
        }
        else {
            dp[n-1][m] < dp[n][m-1] ? --m : --n;
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::string text1 = "abcde", text2 = "ace";
    std::cout << lcs(text1, text2);
}

