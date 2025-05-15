#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int check(int a, int b) {
    return (a + b - 1) / b;
}

int run() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    n *= x;
    m *= y;
    
    vector<vector<char>> v(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    int ans = 0;
    int val = check(x * y, 2);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int res = 0;
            for (int k = i; k < i + x; ++k) {
                for (int t = j; t < j + y; ++t) {
                    if (v[k][t] == 'X') ++res;
                }
            }
            if (res >= val) ++ans;
            j += y - 1;
        }
        i += x - 1;
    }

    return ans;
}


int main() {
    cout << run();
}