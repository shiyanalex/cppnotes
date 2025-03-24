#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_set<char> st;  
    int l = 0;
    int ans = 0;  
    
    for (int r = 0; r < s.size(); r++) {
        
        while (st.contains(s[r])) {
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int lengthOfLongestSubstring2(const string& s) {
    unordered_map<char, int> mapper;
    int l = 0;
    int ans = 0;
    
    for (int r = 0; r < s.size(); r++) {
        if (mapper.contains(s[r])) {
            l = max(l, mapper[s[r]] + 1);
        }
        mapper[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int lengthOfLongestSubstring3(const string& s) {
    vector<int> lastIndex(128, -1);  // ASCII
    int l = 0, ans = 0;
    
    for (int r = 0; r < s.size(); r++) {
        if (lastIndex[s[r]] != -1) {
            l = max(l, lastIndex[s[r]] + 1);
        }
        lastIndex[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    
    return ans;
}


int main() {
    string s = "dvdf";
    cout << lengthOfLongestSubstring(s) << " " << lengthOfLongestSubstring2(s);
}