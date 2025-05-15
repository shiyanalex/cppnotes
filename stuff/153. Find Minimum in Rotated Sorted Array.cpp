#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    
    while (l < r) {
        int m = (r + l) / 2;
        if (nums[m] > nums[r]) l = m + 1;
        else r = m;
    }
    return nums[l];
}

int main() {
    vector<int> vec{1,2};
    cout << findMin(vec);
    //cout << sizeof(vec) << " " << vec.capacity();
}