#include <iostream>

// x^3/y^2 == n, find x and y

// TL
std::pair<int, int> solve(int n) {
    std::pair<int, int> ans;
    int max = 2*n+1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i*i*i) == n*(j*j) && i+j < max) {
                ans = {i, j};
                max = i+j;
            }
        }
    }
    return ans;
}

// also TL
std::pair<ll, ll> solve2(ll n) {
    ll k = 2;
    ll x = 1;
    ll y = 1;
    while (k <= n) {
        ll count = 0;
        while (n % k == 0) {
            count += 1;
            n /= k;
        }
        x *= pow(k, (count / 3) + (count % 3));
        y *= pow(k, count % 3);
        k += 1;
    }
    return std::make_pair(x, y);
}

// should be correct one
std::pair<ll, ll> solve3(ll n) {
    ll x, y;
    for (int k = 0; k < 1000; ++k) {
        x = n / (m * m * m);
        y = n / (m * m);
        if (x*x*x == n*y*y) break;
    }
    return std::make_pair(x, y);
}

int main() {
    ll n;
    std::cin >> n;
    auto ans = solve2(n);
    std::cout << ans.first << " " << ans.second << "\n";
}
