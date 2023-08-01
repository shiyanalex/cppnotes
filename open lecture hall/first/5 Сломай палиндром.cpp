#include <iostream>
#include <vector>

// Break a Palindrome
// WA on test 8

int main() {

    std::string s;
    std::cin >> s;
    int l = s.size();
    
    if (l < 2) {
        return 0;
    }

    bool flag = false;

    for (int i = 0; i < l; ++i) {
        if ((int)s[i] > 97) {
            s[i] = 'a';
            flag = true;
            break;
        }
    }

    if (flag == false) {
        s[l-1]++;
    }

    std::cout << s;
    return 0;
}

