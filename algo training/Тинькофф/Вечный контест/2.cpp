#include <iostream>

int main() {

    long n;
    std::cin >> n;

    int e = 0;
    int p = 1;

    while (p < n) {
        e += 1;
        p *= 2;
    }
    std::cout << e;

}
