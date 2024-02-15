#include <iostream>
#include <map>
#include <set>
using namespace std;

// TL :(
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;

    map<string, int> mapper;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        mapper[s] = i;
    }

    int mp[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }

    set<int> bad;
    for (int i = 0; i < q; ++i) {
        string s; char c; int x;
        cin >> s >> c >> x;
        int id = mapper[s];
        if (c == '>') {
            for (int j = 0; j < n; ++j) {
                if (!bad.count(j) && mp[j][id] <= x) bad.insert(j);
            }
        } else {
            for (int j = 0; j < n; ++j) {
                if (!bad.count(j) && mp[j][id] >= x) bad.insert(j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!bad.count(i)) {
            for (int j = 0; j < m; ++j) ans += mp[i][j];
        }
    }
    cout << ans;
}
