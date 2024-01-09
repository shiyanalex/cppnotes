#include <iostream>
#include <vector>
#define ll long long

ll n, dk, tk, dm, tm;

std::pair<ll, ll> run2() {
    ll kesha = dk * tk;
    ll k = dk;
    ll mel = dm * tm;
    ll m = dm;

    while (k < n && m < n) {
        if (kesha == mel) return {k, m};
        else if (kesha > mel) mel += tm, ++m;
        else if (kesha < mel) kesha += tk, ++k;
    }
    return {n, n};
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> dk >> tk >> dm >> tm;
    auto ans = run2();
    std::cout << ans.first << " " << ans.second;
}
