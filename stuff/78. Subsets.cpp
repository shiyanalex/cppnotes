#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int i, vector<int> curr, vector<vector<int>>& ans, vector<int>& nums) {
    if (i == nums.size()) {
        ans.push_back(curr);
        return;
    }
    
    // Ветка без добавления nums[i]
    dfs(i + 1, curr, ans, nums);
    
    // Ветка с добавлением nums[i]
    curr.push_back(nums[i]);
    dfs(i + 1, curr, ans, nums);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    dfs(0, curr, ans, nums);
    return ans;
}

int main() {
    vector<int> vec{1,2,3};
    for (auto x: subsets(vec)) {
        for (auto y: x) cout << y << " ";
        cout << "\n";
    }
    // nums = [1,2,3] -> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] -> 2^n options
}