#include <iostream>
#include <vector>
#include <numeric>      // std::accumulate
#include <algorithm>    // std::sort
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<long long> vec(n);
    for (auto& x: vec) cin >> x;
    //int start = accumulate(vec.begin(), vec.end(), 0);

    vector<long long> b;
    for (auto x: vec) {
        int e = 1;
        while (x > 0) {
            int ch = x % 10;
            x /= 10;
            b.push_back((9 - ch) * e);
            e *= 10;
        }
    }
    sort(b.rbegin(), b.rend());
    long long ans = 0;
    for (int i = 0; i < min(k, (int)b.size()); ++i) {
        ans += b[i];
    }
    cout << ans;
}

