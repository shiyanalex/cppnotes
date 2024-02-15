#include <iostream>
#include <vector>
#include <algorithm>

// O(очень плохо)
bool check(std::string& s) {
    std::string r = s;
    std::reverse(r.begin(), r.end());
    if (s == r) return true;
    else return false;
}

int pal(std::string& s) {
    int ans = s.size();

    for (int i = 2; i <= s.size(); ++i) {       // размер окна
        for (int j = 0; j < s.size(); ++j) {
            if (j+i > s.size());
            else { 
                std::string tmp = s.substr(j, i);  
                if (check(tmp)) ++ans;
            }
        }
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << pal(s);
}
