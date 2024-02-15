#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

// s0k^n + s1k^n-1 + ... + sn | k = 10
std::vector<ll> direct_hash(std::string& s) {
    std::vector<ll> h(s.size()+1);

    for (int i = 0; i < s.size(); ++i) {
        h[i+1] = h[i]*10 + (s[i]-'`');
    }
    return h;
}

// s0 + s1k + s2k^2+...+ snk^n | k = 10
std::vector<ll> reverse_hash(std::string& s) {
    std::vector<ll> h(s.size()+1);
    int m = 1;
    for (int i = 0; i < s.size(); ++i) {
        h[i+1] = h[i] + (s[i]-'`')*m;
        m *= 10;
    }
    return h;
}

// real hash (reverse)
const int mod = 1e9+7;
const int K = 31;
long long hash = 0, p_pow = 1;

for (size_t i = 0; i<s.length(); ++i){
	hash += (s[i] - 'a' + 1) * p_pow;
	p_pow *= p;
}

std::vector<ll> h;
std::vector<ll> p;
std::vector<ll> hash(std::string& s) {
    h.resize(s.size());
    p.resize(s.size() + 1, 1);

    for (int i = 0; i < s.size(); ++i) {
        h[i+1] = (h[i] + (s[i]-'`')*p[i]) % mod;
        p[i+1] = (p[i] * K) % mod;
    }
    return h;
}


int check(int l, int r) {
    return (h[r] - h[l]) * p[n-l] % mod;
}

bool compare(int l, int a, int b) {
    if (a+l <= n && b+l <= n) {
        if (check(a, a+l) == check(b, b+l)) {
            return true;
        }
        return false;
    }
    return false;
}
*/

int main() {
    std::string s = "abcabd";
    //std::cin >> s;
    //n = s.size();
    //int m; std::cin >> m;

    for (auto x: direct_hash(s)) std::cout << x << "\n";
    std::cout << s << "\n";
    for (auto x: reverse_hash(s)) std::cout << x << "\n";
    std::cout << s;

    /*for (auto x: p) std::cout << x << "\n";
    std::cout << " \n";
    for (auto x: h1) std::cout << x << "\n";
    std::cout << check(0, 2) << " " << check(2, 4) << "\n";
    */
    /*
    for (int i = 0; i < m; i++) {
        int l, a, b;
        std::cin >> l >> a >> b;
        if (l == 1) {
            (s[a] == s[b]) ? std::cout << "yes\n" : std::cout << "no\n";
        }
        else std::cout << (compare(l, a, b) ? "yes\n" : "no\n");
    }
    return 0;
    */
}
