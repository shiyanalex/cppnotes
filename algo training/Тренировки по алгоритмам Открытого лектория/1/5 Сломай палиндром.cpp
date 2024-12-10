#include <iostream>
#include <vector>

int main() {
    std::string s;
    getline (std::cin, s);
    int l = s.size();
    if (l < 2) {
        std::cout << "";
    }
    bool flag = false;
    int mid = s.length() / 2;
    
    for (int i = 0; i < mid; ++i) {
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

