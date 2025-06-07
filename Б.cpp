#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define int long long

void Solve() {
    int n;
    cin >> n;

    vector<int> q(n), c(n);
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        sum += q[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << sum * a << '\n';
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        double rate = c[i] * (b - a) / 255.0 + a;
        ans += ceil(q[i] * rate);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
