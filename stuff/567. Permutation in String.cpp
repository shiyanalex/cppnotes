#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    int n = s1.size();
    unordered_map<char, int> mapper;
    unordered_map<char, int> window;
    
    for (int i = 0; i < n; ++i) {
        ++mapper[s1[i]];
        ++window[s2[i]];
    }
    
    for (int i = n; i < s2.size(); ++i) {
        if (mapper == window) return true;
        --window[s2[i-n]];
        if (window[s2[i - n]] == 0) window.erase(s2[i - n]);
        ++window[s2[i]];
    }
    return mapper == window;
}


bool checkInclusion2(std::string s1, std::string s2) {
    if (s1.size() > s2.size()) return false;
    
    int n = s1.size();
    std::vector<int> count1(26, 0), count2(26, 0);
    
    for (int i = 0; i < n; ++i) {
        ++count1[s1[i] - 'a'];
        ++count2[s2[i] - 'a'];
    }
    
    if (count1 == count2) return true;
    
    for (int i = n; i < s2.size(); ++i) {
        ++count2[s2[i] - 'a'];
        --count2[s2[i - n] - 'a'];
        
        if (count1 == count2) return true;
    }
    
    return false;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
}