#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    map<int, int> total;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++total[x];
    }

    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        --total[x];
    }
    int count = 0;
    for (auto x: total) count += abs(x.second);
    
    for (int i = 0; i < q; ++i) {
        int type;
        char player;
        int card;
        cin >> type >> player >> card;
        
        if (player == 'A') {
            count -= abs(total[card]);
            total[card] += type;
            count += abs(total[card]);
        } else {
            count -= abs(total[card]);
            total[card] -= type;
            count += abs(total[card]);
        }
        cout << count << "\n";
    }
}

