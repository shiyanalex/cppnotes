#include <iostream>
#include <vector>

// Break a Palindrome
// WA on test 5

bool allCharactersSame(std::string& s) {
    int n = s.length();
    for (int i = 1; i < n; i++)
        if (s[i] != s[0])
            return false;
 
    return true;
}
 

int main() {

    std::string s;
    std::cin >> s;
    
    std::vector<char> v;
    for (int i = 0; i < s.size(); ++i) {
        v.push_back(s[i]);
    }

    if (allCharactersSame(s) == true) {
        return 0;
    }
    
    for (int i = 0; i < s.size(); ++i) {
        if ((int)v[i] > 97) { 
            v[i]--;
            break;
        }
    }
    
    for (char c : v) { std::cout << c; }
}

