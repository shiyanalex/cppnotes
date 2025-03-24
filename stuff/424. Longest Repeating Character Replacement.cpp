#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char, int> frequency;
    int ans = 0;
    int l = 0;
    int max_freq = 0;
    
    for (int r = 0; r < s.size(); r++) {
        ++frequency[s[r]];
        max_freq = max(max_freq, frequency[s[r]]);
        
        if ((r - l + 1) - max_freq > k) {
            frequency[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int characterReplacement2(string s, int k) {
    vector<int> frequency(26, 0);
    int l = 0, ans = 0;
    int max_freq = 0;
    
    for (int r = 0; r < s.size(); r++) {
        ++frequency[s[r] - 'A'];
        
        max_freq = max(max_freq, frequency[s[r] - 'A']);
        
        if ((r - l + 1) - max_freq > k) {
            --frequency[s[l] - 'A'];
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main() {
    string s = "AABABBA";
    cout << characterReplacement(s, 1) << " " << characterReplacement2(s, 1);
}