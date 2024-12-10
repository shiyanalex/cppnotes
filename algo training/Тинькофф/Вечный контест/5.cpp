#include <iostream>
#include <vector>
#include <cmath>
#define int long long
using namespace std;

// WA test 61
int32_t main() {
    
    int l, r;
    cin >> l >> r;
    vector<int> vec;

    //Repdigit numbers formula
    int rr = log10(r) + 1;
    for (int k = 1; k <= rr; ++k) {
        for (int u = 0; u++ < 9;) {
            int num = u * ((pow(10, k) - 1) / 9);
            if (num >= l && num <= r) vec.emplace_back(num);
        }
    }
    //for (auto x: vec) cout << x << "\n";
    cout << vec.size();
    //cout << distance(lower_bound(vec.begin(), vec.end(), l), lower_bound(vec.begin(), vec.end(), r+1));
    return 0;
}

