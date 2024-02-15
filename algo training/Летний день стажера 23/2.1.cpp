#include <iostream>
#include <map>
using namespace std;

bool check(string& s1, string& s2) {
    map<char, char> mapper;

    for (int i = 0; i < s1.size(); ++i) {
        if (mapper.contains(s1[i])) {
            if (mapper[s1[i]] == s2[i]);
            else return false;
        } 
        else {
            for (auto x: mapper)
                if (x.second == s2[i] && x.first != s1[i]) return false;
        }
        mapper[s1[i]] = s2[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        check(s1, s2) ? cout << "yes\n" : cout << "no\n";
    }
}

