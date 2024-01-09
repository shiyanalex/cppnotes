#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 24 60 = 16
// 12 1234 = 4

int reverse(int x, int k) {
    int res = 0;

    for (int i = 0; i < k; ++i) {
        int t = x%10;
        x = x/10;
        res = res*10 + t;
        t = 0;
    }
    return res;
}

int main() {

    int n, m;
    std::cin >> n >> m;
    n = n-1;
    m = m-1;
    int ans = 0;

    int max = std::max(n, m);
    int k = 0;
    while (max > 0) {
        int digit = max % 10;
        max /= 10;
        ++k;
    }

    for (int i = 0; i <= n; ++i) {
        if (reverse(i, k) <= m) ++ans;
    }

    std::cout << ans;

    /*
    std::vector<int> nn; 
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        nn.push_back(digit);
    }

    std::vector<int> mm; 
    while (m > 0) {
        int digit = m % 10;
        m /= 10;
        mm.push_back(digit);
    }

    int gmin = std::min(nn.size(), mm.size());
    std::cout << std::pow(2, gmin);

    auto it1 = nn.rbegin();
    auto it2 = mm.begin();

    
    */


}
