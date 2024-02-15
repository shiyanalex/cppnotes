#include <iostream>
#include <vector>
#include <map>

bool howSum(int target, const std::vector<int>& nums, std::vector<int>& ans) {
    if (target == 0) return true;
    if (target < 0) return false;

    for (auto& x: nums) {
        int remainder = target - x;
        if (howSum(remainder, nums, ans) == true) {
            ans.emplace_back(x);
            return true;
        }
    }
    return false;
}

void call(int a, std::vector<int> vec) {
    std::vector<int> ans;
    if (howSum(a, vec, ans)) for (auto x: ans) std::cout << x << " ";
    else std::cout << "-";
    std::cout << "\n";
}

bool howSum2(int target, const std::vector<int>& nums, std::vector<int>& ans, std::map<int, bool>& dp) {
    if (target == 0) return true;
    if (target < 0) {
        dp[target] = false;
        return false;
    }
    if (dp.find(target) != dp.end()) return dp[target];

    for (auto& x: nums) {
        int remainder = target - x;
        if (howSum2(remainder, nums, ans, dp) == true) {
            ans.emplace_back(x);
            return true;
        }
    }
    dp[target] = false;
    return false;
}

void call2(int a, std::vector<int> vec) {
    std::vector<int> ans;
    std::map<int, bool> dp;
    if (howSum2(a, vec, ans, dp)) for (auto x: ans) std::cout << x << " ";
    else std::cout << "-";
    std::cout << "\n";
}

int main() {
    call(7, std::vector<int> {2, 3});
    call(7, std::vector<int> {5, 3, 4, 7});
    call(7, std::vector<int> {2, 4});
    call(8, std::vector<int> {2, 3, 5});
    //call(300, std::vector<int> {7, 14});
    std::cout << "\n";
    call2(7, std::vector<int> {2, 3});
    call2(7, std::vector<int> {5, 3, 4, 7});
    call2(7, std::vector<int> {2, 4});
    call2(8, std::vector<int> {2, 3, 5});
    call2(300, std::vector<int> {7, 14});
}
