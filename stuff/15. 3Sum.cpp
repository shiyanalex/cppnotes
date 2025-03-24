#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int l = i + 1, r = n - 1;
        
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            
            if (sum == 0) {
                ans.push_back({nums[i], nums[l], nums[r]});
                ++l; --r;
                while (l < r && nums[l] == nums[l + 1]) ++l;
                while (l < r && nums[r] == nums[r - 1]) --r;
            } 
            else if (sum > 0) --r;
            else ++l; 
        }
    }
    
    return ans;
}

int main() {
    vector<int> vec {-1, 0, 1, 2, -1, -4};

    for (auto x: threeSum(vec)) {
        for (auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}
