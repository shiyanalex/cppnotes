#include <iostream>

// https://contest.yandex.ru/contest/53030/problems/

bool good(int l, int a, int b, std::string& s) {
    for (int i = 0; i < l; ++i) {
        if (s[a] != s[b]) return false;
        ++a, ++b;
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, a, b;
        std::cin >> l >> a >> b;
        if (good(l, a, b, s)) std::cout << "yes\n";
        else std::cout << "no\n";
    }
}
