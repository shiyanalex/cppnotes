#include <iostream>
#define int long long
using namespace std;
int n, a, b, w, h;

int check1(int j) {
    int aa = h / (a + 2*j);
    int bb = w / (b + 2*j);
    return aa*bb;
}

int check2(int j) {
    int aa = h / (b + 2*j);
    int bb = w / (a + 2*j);
    return aa*bb;
}

int lsearch() {
    int l = 0;
    int r = std::max(w, h);
    while (l < r) {
        int m = (l+r)/2;
        if (check1(m) < n && check2(m) < n) r = m;
        else l = m+1;
    }
    return l-1;
}

int32_t main() {
    cin >> n >> a >> b >> w >> h;
    /* TL 
    for (int i = 0; i < std::max(w, h); ++i) {
        int j = i + 1;
        if (check1(j) < n && check2(j) < n) { cout << i; return 0;};
    }
    */
    cout << lsearch();
    return 0;
}

