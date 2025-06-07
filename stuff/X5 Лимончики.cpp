#include <iostream>
using namespace std;

int main() {
    //int q = 20, h = 30, s = 70, d = 90, n = 3;
    int q = 10000, h = 1000, s = 100, d = 10, n = 1;

    //int q, h, s, d, n;
    //cin >> q >> h >> s >> d >> n;
    
    q *= 4;
    h *= 2;
    int k = min(min(q, h), s);

    if (d <= 2*k) {
        if (n % 2 == 0) return n / d;
        else {
            cout << ((n/2)*d + ((n % 2) * k));
        }
    }
    else cout << "b" << n / k;
    return 0;
}