#include <iostream>
#include <vector>

// O(Nlogn) таблом Юнга без возможности восстановления
void lislen(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp;
    dp.push_back(nums[0]);

    for(int i = 1; i < n; ++i) {
        if (dp.back() < nums[i]) {
            dp.push_back(nums[i]);
        }
        else {
            int k = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[k] = nums[i];
        }
    }
    std::cout << dp.size() << "\n";
}

// храним минимальное число на которое может оканчиваться нвп длинны i
std::vector<int> LIS(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, -1);
    dp[0] = nums[0];

    for(int i = 1; i < n; ++i) {
        if ()
    }
    std::cout << dp.size() << "\n";
}

int main() {
    std::vector<int> vec{3,5,1,6,2,8,9,4};
    LIS(vec);
}
