#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> max_right(n);
    int ans = 0;
    int curr = 0;
    
    for (int i = n-1; i >= 0; --i) {
        curr = max(curr, prices[i]);
        max_right[i] = curr;
    }
    
    for (int i = 0; i < n; ++i) {
        ans = max(ans, max_right[i] - prices[i]);
    }
    return ans;
}

int maxProfit2(vector<int>& prices) {
    int profit = 0;
    int buy = prices[0];
    
    for (auto x: prices) {
        buy = min(buy, x);
        profit = max(profit, x - buy);
    }
    return profit;
}

int main() {
    vector<int> vec{7,1,5,3,6,4};
    cout << maxProfit(vec) << " " << maxProfit2(vec);
}