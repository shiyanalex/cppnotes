#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;
    stack<pair<int, int>> st; // {index, height}
    
    for (int i = 0; i < n; ++i) {
        int start = i;
        while (!st.empty() && st.top().second > heights[i]) {
            auto [index, height] = st.top();
            st.pop();
            ans = max(ans, height * (i - index));
            start = index;
        }
        st.push({start, heights[i]});
    }
    
    // Final cleanup: remaining items in stack
    while (!st.empty()) {
        auto [index, height] = st.top();
        st.pop();
        ans = max(ans, height * (n - index));
    }
    
    return ans;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
}