#include <iostream>
#include <vector>

// переставить нули в конец

class Solution283 {
public:
    void moveZeroes(std::vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (*it == 0) {
                nums.erase(it);
                nums.push_back(0);
            }
        
        }
        for (auto x : nums) std::cout << x << ",";
    }
};

class Solution2831 {
public:
    void moveZeroes(std::vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[j], nums[i]);
                j++;
            }
        }
        for (auto x : nums) std::cout << x << ",";
    }
};

void f(int x) {
    if ((x&1) == 0) {
        std::cout << "nice";
    }
}

int main() {

    std::vector<int> v{5,0,1,0,3,12};
    Solution283 s;
    s.moveZeroes(v);
    int t = 6;
    f(t);

}
