#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int open, int close, string curr, vector<string>& ans) {
    if (open == 0 && close == 0) {
        ans.push_back(curr);
        return;
    }
    
    if (open > 0) dfs(open - 1, close, curr + "(", ans);
    if (close > open) dfs(open, close - 1, curr + ")", ans);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string curr = "";
    
    dfs(n, n, curr, ans);
    return ans;
}

int main() {
    for (auto x: generateParenthesis(3)) cout << x << "\n";
}