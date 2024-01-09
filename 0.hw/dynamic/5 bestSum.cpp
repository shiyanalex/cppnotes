#include <iostream>
#include <vector>

bool bestSum(int target, const std::vector<int>& nums, std::vector<int>& ans) {
    if (target == 0) return true;
    else if (target < 0) return false;
    
    for (auto x: nums) {
        int remainder = target - x;
        if (bestSum(remainder, nums, ans) == true) {
            ans.push_back(x);
            if (ans.size() < best.size()) best = ans, ans.empty();
            return true;
        }
    }
    return false;
}

void call(int a, std::vector<int> vec) {
    /*std::vector<int> ans;
    if (bestSum(a, vec, ans)) for (auto x: best) std::cout << x << " ";
    else std::cout << "-";
    std::cout << "\n";
    */
    for (auto x: bestSum1(a, vec)) std::cout << x << " ";
}


int coinChange(std::vector<int>& vec, int need) {
    std::vector<int> dp(need+1, INT_MAX-1);
    dp[0] = 0;
    
    for (int i = 1; i <= need; ++i) {
        for (auto& x: vec) {
            if (i - x >= 0) dp[i] = std::min(dp[i], 1 + dp[i-x]);
        }
    }
    if (dp[need] != INT_MAX) return dp[need];
    else return -1;
}

std::vector<int> bestSum1(int target, const std::vector<int>& nums) {
    std::vector<int> dp(target+1, INT_MAX-1);
    dp[0] = 0;

    for (int i = 0; i <= target; ++i) {
        for (auto x: nums) {
            if (target - x >= 0) dp[i] = std::min(dp[i], 1 + dp[i-x]);
        }
    } 
    if (dp[need] != INT_MAX) return dp[need];
    else return {};
}

/*
bool bestSum2(int target, const std::vector<int>& nums, std::vector<int>& ans, std::map<int, bool>& dp) {
    if (target == 0) return true;
    else if (target < 0) return false;
    
    for (auto x: nums) {
        int remainder = target - x;
        if (check(remainder, nums, ans) == true) {
            ans.push_back(x);
        }
    }
    return false;
}

void call2(int a, std::vector<int> vec) {
    std::vector<int> ans;
    std::map<int, bool> dp;
    if (bestSum(a, vec, ans, dp)) for (auto x: ans) std::cout << x << " ";
    else std::cout << "-";
    std::cout << "\n";
}
*/

int main() {
    call(7, {2, 3});
    call(7, {5, 3, 4, 7});
    call(7, {2, 4});
    call(8, {2, 3, 5});

    //call(300, {7, 14});
}
