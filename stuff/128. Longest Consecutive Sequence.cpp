#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(nlog(n))
int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    for (auto x: nums) cout << x << " ";
    cout << "\n";

    int ans = 0;
    int curr = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i-1] != nums[i]) {
            if (nums[i-1]+1 == nums[i]) ++curr;
            else ans = std::max(curr, ans), curr = 1;   
        }
    }
    return std::max(curr, ans);
}

// O(n)
int longestConsecutive2(vector<int>& nums) {
    unordered_map<int, bool> mapper;
    for (auto x: nums) mapper[x] = true;
    for (auto x: nums) if (mapper.contains(x-1)) mapper[x] = false; // now start of each seq is True and everything else is False
    // for (auto x: mapper) cout << x.first << " " << x.second << "\n";
    // lets find the longest seq then, shall we cheers my friends
    int ans = 0;
    for (auto x: mapper) {
        if (x.second == true) {
            int j = 0;
            while (mapper.contains(x.first+j)) ++j;
            ans = max(j, ans);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive2(nums) << "\n";
    cout << longestConsecutive2(nums2);
}
