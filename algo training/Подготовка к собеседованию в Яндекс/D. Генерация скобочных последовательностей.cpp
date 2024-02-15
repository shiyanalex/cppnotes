#include <iostream>
#include <string>

void foo(std::string s, int l, int r, int pairs) {
    if (l == pairs && r == pairs) {
        std::cout << s << std::endl;
    } else {
        if (l < pairs) {
            foo(s + '(', l + 1, r, pairs);
        }
        if (r < l) {
            foo(s + ')', l, r + 1, pairs);
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    foo("", 0, 0, n);
    return 0;
}

