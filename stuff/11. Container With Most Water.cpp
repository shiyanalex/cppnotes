#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int maxArea(vector<int>& heights) {
    int n = heights.size();
    int l = 0;
    int r = n - 1;
    int ans = 0;
    
    while (l < r) {
        int curr = min(heights[l], heights[r]) * (r - l);
        ans = max(curr, ans);
        if (heights[l] < heights[r]) ++l;
        else --r;
    }
    return ans;
}


int main() {
    vector<int> vec{1,7,2,5,4,7,3,6};
    vector<int> vec2{1,8,6,2,5,4,8,3,7};
    cout << maxArea(vec2);
}