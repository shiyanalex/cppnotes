#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int k;
string s, t;
unordered_map<char, int> mapper;

string find() {
    for (auto i = 0; i < s.size() - k+1; ++i) {
        bool flag = true;
        string str = s.substr(i, i+k);
        unordered_map<char, int> mp;
        for (auto x: str) ++mp[x];

        for (auto x: mp) {
            if (!mapper.contains(x.first) || mapper[x.first] < x.second) {flag = false; break; }
        }
        if (flag) return "YES";
    }
    return "NO";
}

int main() {
    cin >> k;
    cin >> s >> t;

    for (int i = 0; i < t.size(); ++i) {
        ++mapper[t[i]];
    }
    //for (auto x: mapper) cout << x.first << " " << x.second << "\n";
    cout << find();
}

