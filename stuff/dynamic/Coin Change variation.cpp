#include <iostream>
#include <vector>
#include <map>
using namespace std;
// DP bottom up
// Return the fewest number of coins that make up that amount, else return -1.

vector<int> coinVariation(int need, std::vector<int> vec) {
    map<int, vector<int>> dp;
    dp[0] = {};
    
    for (auto x: vec) {
        for (int i = 1; i <= need; ++i) {
            if (i - x == 0) dp[i] = {x};
            else if (i - x > 0 && dp.count(i-x)) {
                vector<int> comp = {x};
                copy(begin(dp[i-x]), end(dp[i-x]), back_inserter(comp));
                if (!dp.count(i) || comp.size() < dp[i].size()) dp[i] = comp;
            }
        }
        //for (auto x: dp) cout << x << " ";
        //cout << "\n";
    }
    /*
    for (auto x: dp) {
        for (auto y: x.second) cout << y << "";
        cout << " | ";
    }
    cout << "\n";
    */
    return dp[need];
}

void call(int a, std::vector<int> vec) {
    for (auto x: coinVariation(a, vec)) cout << x << " ";
    cout << "\n";
}

int main() {
    call(7, {5, 3, 4, 7}); // 7
    call(8, {2, 3, 5});    // 3 5
    call(8, {1, 4, 5});    // 4 4
    call(100, {2, 3, 5});    
}
