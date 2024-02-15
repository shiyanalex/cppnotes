#include <iostream>
#include <cmath>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int l = 0;
    int r = x;

    /*
    while (l < r) {
        int m = (l+r)/2;
        long m2 = m * m;
        std::cout << "|" << m << " " << m2 << " " << l << " " << r << "\n";
        if (m2 == x) return m;
        else if (m2 > x) r = m;
        else l = m + 1;
    }
    */

    while (l < r) {
        int m = (l+r)/2+1;
        long m2 = m * m;
        //std::cout << "|" << m << " " << m2 << " " << l << " " << r << "\n";
        if (m2 == x) return m;
        else if (m2 > x) r = m-1;
        else l = m;
    }

    return l;
}

int Sqrt(int x) {
    long r = x;
    while (r*r > x)
    r = (r + x/r) / 2;
    return r;
}

int main() {
    int x;
    std::cin >> x;
    std::cout << mySqrt(x);
}
