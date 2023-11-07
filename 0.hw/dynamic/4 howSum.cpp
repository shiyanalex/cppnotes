#include <iostream>
#include <vector>
#include <map>

int i = 1;
int j = 1;
std::vector<int> ans;

bool howSum2(int target, const std::vector<int>& nums, std::map<int, bool>& dp) {
    ans.clear();
    if (target == 0) return true;
    if (target < 0) return false;
    
    if (dp.find(target) != dp.end()) return dp[target];

    for (auto& x: nums) {
        int remainder = target - x;
        if (howSum2(remainder, nums, dp) == true) {
            dp.emplace(remainder, true);
            ans.push_back(x);
            return true;
        }
    }
    dp.emplace(target, false);
    return false;
}

bool howSum(int target, const std::vector<int>& nums) {
    ans.clear();
    if (target == 0) return true;
    if (target < 0) return false;

    for (auto& x: nums) {
        int remainder = target - x;
        if (howSum(remainder, nums) == true) {
            ans.push_back(x);
            return true;
        }
    }
    return false;   // not possible
}

void call(int a, std::vector<int> v1) {
    howSum(a, v1);
    std::cout << i << "| ";
    for (auto& x: ans) std::cout << x << " ";
    std::cout << "\n";
    ++i;
}

void call2(int a, std::vector<int> v1) {
    std::map<int, bool> dp;
    howSum2(a, v1, dp);
    std::cout << j << "| ";
    for (auto& x: ans) std::cout << x << " ";
    std::cout << "\n";
    ++j;
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
