#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    
    vector<int> max_left(n);
    vector<int> max_right(n);
    int ans = 0;
    int curr = 0;
    
    for (int i = 0; i < n; ++i) {
        curr = max(curr, height[i]);
        max_left[i] = curr;
    }
    curr = 0;
    for (int i = n-1; i > 0; --i) {
        curr = max(curr, height[i]);
        max_right[i] = curr;
    }
    for (int i = 0; i < n; ++i) {
        int k = min(max_left[i], max_right[i]) - height[i];
        if (k > 0) ans += k;
    }

    return ans;
}

int trap2(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int l = 0;
    int r = n - 1;
    
    int max_l = height[l];
    int max_r = height[r];
    int ans = 0;
    
    while (l < r) {
        if (height[l] < height[r]) {
            max_l = max(height[l], max_l);
            ans += max_l - height[l];
            ++l;
        } else {
            max_r = max(height[r], max_r);
            ans += max_r - height[r] ;
            --r;
        }
    }
    return ans;
}

int main() {
    vector<int> vec{0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> vec2{4,2,0,3,2,2};
    cout << trap(vec2) << "\n" << trap2(vec2);

}