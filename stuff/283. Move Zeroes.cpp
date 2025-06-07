#include <iostream>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            //std::swap(nums[j], nums[i]);
            nums[j] = nums[i];
            if (i != j) nums[i] = 0;
            ++j;
        }
    }
    //for (auto x : nums) std::cout << x << ",";
}

int main() {
    std::vector<int> v{5,0,1,0,3,12};
    moveZeroes(v);
    
}
