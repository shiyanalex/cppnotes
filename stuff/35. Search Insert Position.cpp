#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n;
    
    while (l < r) {
        int m = l + (r-l) / 2;
        cout << m << nums[m] << "\n";
        if (nums[m] > target) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    vector<int> vec {1,3,5,6};
    cout << searchInsert(vec, 2);
    
}