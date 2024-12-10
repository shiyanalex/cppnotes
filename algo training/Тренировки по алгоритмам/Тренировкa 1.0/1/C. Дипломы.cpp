#include <iostream>
#define int long long
using namespace std;
int w, h, n;

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

int32_t main() {
    cin >> w >> h >> n;
    int max = std::max(w, h);
    /* TL
    for (int i = max; i < max*n+1; ++i) {
        if ( ((i/w) * (i/h)) >= n) { cout << i; return 0; }
    }
    */
    cout << lsearch();
}

