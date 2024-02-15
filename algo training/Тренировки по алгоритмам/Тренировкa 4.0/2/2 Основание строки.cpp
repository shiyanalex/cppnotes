#include <iostream>

// O(n^2)
int check(std::string& s) {
    std::string ans;
    for (int i = 1; i <= s.size(); ++i) {        // size of substring
        bool flag = true;
        for (int j = 0; j < s.size(); j += i) { // iterating over string
            if (i+j > s.size()) {
                int t = s.size() - j;
                if (s.substr(0, t) != s.substr(j, t)) flag = false;
            }
            else if (s.substr(0, i) != s.substr(j, i)) flag = false;
        }
        if (flag) {
            //ans = s.substr(0, i);
            //std::cout << ans << "\n";
            return i;
        }
    }
    return s.size();
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << check2(s);
}
