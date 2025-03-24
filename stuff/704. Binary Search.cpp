#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    
    while (l <= r) {
        int m = (r + l) / 2;
        if (nums[m] == target) return m;
        if (nums[m] < target) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    vector<int> vec{3,6,7,9};
    int target = 9;
    cout << search(vec, target);
}