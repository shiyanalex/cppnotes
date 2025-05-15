#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int k = n + m;
    vector<int> merge (k, 0);
    
    int a = 0, b = 0, i = 0;
    while (a < m && b < n) {
        if (nums1[a] <= nums2[b]) merge[i++] = nums1[a++];
        else merge[i++] = nums2[b++];
    }
    while (a < m) merge[i++] = nums1[a++];
    while (b < n) merge[i++] = nums2[b++];

    for (auto x: merge) cout << x << " ";
    if (k % 2 == 0) {
        return (merge[k/2-1] + merge[k/2]) / 2.0;
    }
    else return merge[k/2];
}

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2);
}