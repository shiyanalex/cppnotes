#include <iostream>
#include <vector>
#include <map>

std::string check(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return "NO\n";
    }
    std::map<char, char> dicts;
    std::map<char, char> dictt;
    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];
        if (dicts.find(c1) == dicts.end()) {
            dicts[c1] = c2;
        } else if (dicts[c1] != c2) {
            return "NO\n";
        }
        if (dictt.find(c2) == dictt.end()) {
            dictt[c2] = c1;
        } else if (dictt[c2] != c1) {
            return "NO\n";
        }
    }
    return "YES\n";
}

int main() {

    int n;
    std::cin >> n;

    std::vector<std::string> s1;
    std::vector<std::string> s2;

    for (int i = 0; i < 2*n; ++i) {
        std::string s;
        std::cin >> s;

        if ((i&1) == 0) {
            s1.push_back(s);
        } else {
            s2.push_back(s);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << check(s1[i], s2[i]);
    }

    /*
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < s1[j].size(); ++i) {
            // replace all characters
            char a = s1[j][0];
            char b = s2[j][0];

            if (s1[j][i] == a) {
                s1[j][i] = b;
            } else {
                s1[j][i] = s2[j][i];
            }
        }
    } 

    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) std::cout << "YES\n";
        else std::cout << "NO\n";

    } */


}
