#include <iostream>
#include <cmath>
#define int long long
using namespace std;
int a, b, c;
/*
bool good(int i) {
    if ( ((i/w) * (i/h)) >= n) return true;
    else return false;
}

int lsearch() {
    int l = std::max(w, h);
    int r = std::max(w, h) * n;
    while (l < r) {
        int m = (l+r)/2;
        if (good(m)) r = m;
        else l = m+1;
    }
    return l;
}
*/

int32_t main() {
    cin >> a >> b >> c;
    cout << (a == 0 && b == 0 ? 0 : (int)(std::ceil(a + b / 3.0 - c / 3.0)));
}

