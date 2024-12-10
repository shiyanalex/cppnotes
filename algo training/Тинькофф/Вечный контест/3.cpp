#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, t;
    cin >> n >> t;
    vector<int> vec(n);
    for (auto& x: vec) cin >> x;
    int x;
    cin >> x;
    x -= 1;

    int a = vec[x] - vec[0];
    int b = vec[n-1] - vec[x];
    if (a <= t || b <= t) cout << vec[n-1] - vec[0];
    else cout << min(a, b) + vec[n-1] - vec[0];
}

