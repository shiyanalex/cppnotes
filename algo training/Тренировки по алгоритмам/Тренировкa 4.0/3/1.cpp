#include <iostream>
using namespace std;
int n, s, f;
int map[n][n];

int dijkstra() {
    int dp[n][n];
    for (int i = 0; i < n; ++i) {
        
    }
}

int main() {
    cin >> n >> s >> f;
    int map[n][n];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int x; cin >> x;
            map[i][j] = x;
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dijkstra();
}
