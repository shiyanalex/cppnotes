#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int max = 0;
    int curr = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 1) ++curr;
        else { 
            max = std::max(max, curr);
            curr = 0;
        }
    }
    max = std::max(max, curr);
    std::cout << max;
}

