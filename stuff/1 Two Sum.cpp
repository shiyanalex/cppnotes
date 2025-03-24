#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
int max(T data) {
    int max = 0;
    for (auto& x: data) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}

// O(n^2)
std::vector<int> twoSum1(std::vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// O(n)
std::vector<int> twoSum2(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::unordered_map<int, int> mapper;

    for (int i = 0; i < n; i++) {
        int need = target - nums[i];
        if (mapper.contains(need)) return {mapper[need], i};
        mapper[nums[i]] = i;
    }
    return {};
}

