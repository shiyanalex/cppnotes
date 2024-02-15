#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
//#define int long long

// WA
// нихера на понял, но очень интересно
int32_t main() {
    int k, n;
    cin >> k >> n;
    vector<int> vec(n+1);
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        vec[i] = x;
        if (x > 0) last = i;
    }
    int sum_of_elems = std::accumulate(vec.begin(), vec.end(), 0);
    cout << sum_of_elems << "|";

    int ans = 0;
    int curr = 0;
    for (int i = 1; i <= last; ++i) {
        cout << vec[i]+curr / k << "\n";
        int now = vec[i] + curr;

        if (i == last) {
            now % k == 0 ? (ans += 2*i * (now / k)) : (ans += 2*i * (now / k) + 1);
        }
        else if (vec[i]+curr >= k) {
            ans += 2*i * (now / k);
            curr = now % k;
        }
        else if (vec[i]+curr < k) curr += vec[i], vec[i] = 0;
    }
    cout << ans;
}
