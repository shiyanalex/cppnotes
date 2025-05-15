#include <iostream>
#include <vector>
using namespace std;

int coinCombinations(int need, vector<int> vec) {
    vector<int> dp(need+1);
    dp[0] = 1;
    
    for (auto x: vec) {
        for (int i = 1; i <= need; ++i) {
            if (i - x >= 0) dp[i] += dp[i-x];
        }
    }
    for (auto x: dp) cout << x << " ";
    cout << "\n";
    return dp[need];
}

int main() {
    vector<int> vec{1,2,5};
    cout << coinCombinations(5, vec);
}
