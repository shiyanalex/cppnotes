#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int even = n/2;
    int e = 0;
    int a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if ((x&1) == 0) ++e;
        if (x % 2 == 0 && i % 2 == 1) a = i;
        if (x % 2 == 1 && i % 2 == 0) b = i;
    }
    if (a == 0 && n > 2) cout << 1 << " " << 3; // if seq is right
    else if (even == e && a != 0) cout << a << " " << b; // if we swapped
    else cout << -1 << " " << -1; // else
}

