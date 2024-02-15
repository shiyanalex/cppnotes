#include <iostream>
#include <cmath>

void rational(double num) {
    int dec = 100;
    int p = floor(num * dec);
    int q = dec;
    for (int qq = 1; qq < q; qq++) {
        for (int pp = 1; pp < p; pp++) {
            if ((dec * pp / qq) == p) {
                std::cout << pp << " " << qq << std::endl;
                return;
            }
        }
    }
    std::cout << p << " " << q << std::endl;
}

int main() {
    double in;
    std::cin >> in;
    rational(in);
    return 0;
}
