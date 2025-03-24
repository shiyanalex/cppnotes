#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow_(string s, string t) {
    if (s.size() < t.size()) return "";
    
    int n = s.size();
    unordered_map<char, int> target;
    unordered_map<char, int> window;
    for (auto x: t) ++target[x];
    
    int start = 0;
    int min_len = INT_MAX;
    int have = 0;
    int l = 0;
    
    for (int r = 0; r < n; ++r) {
        char c = s[r];
        ++window[c];
        if (target.contains(c) && target[c] == window[c]) ++have;

        while (have == target.size()) {
            if (r - l + 1 < min_len) { 
                min_len = r - l + 1;
                start = l;
            }
            
            --window[s[l]];
            if (target.contains(s[l]) && window[s[l]] < target[s[l]]) --have;
            ++l;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int> map(256,0);
    
    for(int i = 0 ; i < m ;i++) map[t[i]]++;
    
    int left = 0;
    int right = 0;
    int count = 0;
    int start = -1;
    int minlen = n+1;
    
    while(right < n){
        
        if(map[s[right]] > 0) count++;
        map[s[right]]--;
        
        while(count == m){
            
            if(right - left + 1 < minlen){
                minlen = right - left + 1;
                start = left;
            }
            
            map[s[left]]++;
            
            if(map[s[left]] > 0) count--;
            
            left++;
        }
        
        right++;
    }
    return start == -1 ? "" : s.substr(start,minlen);
}


int main() {
    string s = "aa", t = "aa";
    cout << minWindow(s, t);
}