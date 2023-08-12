#include <iostream>
#include <vector>

int main() {

    int n, prev;
    std::cin >> n;

    /*for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        
        // !i if 0 returns 1 else 0
        if (!i || x != prev) {
            std::cout << x << "\n";
            prev = x;
        }
    } */

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        
        if (i == 0 || x != prev) {
            std::cout << x << "\n";
            prev = x;
        }
    }
        
}
