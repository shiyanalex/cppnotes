#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // 2^e >= n
    int e = 0;
    long p = 1;
    while (p < n) {
        e++;
        p *= 2;
    }
    std::cout << e;
}


