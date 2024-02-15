#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int k, a, b;
vector<pair<int, int>> vec;


void bfs(int s, const std::vector<std::vector<int>>& adj) {
    std::vector<int> cost(adj.size(), -1);

    cost[s] = 0;
    std::queue<int> queue;
    queue.push(s);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (int w : adj[v]) {

            if (cost[w] == -1) {

                queue.push(w);

                cost[w] = cost[v] + 1;
            }
        }
    }
}


int dist(int a, int b) {
    a -= 1, b -=1;
    return abs(vec[a].first - vec[b].first) + abs(vec[a].second - vec[b].second);
}


int run(vector<pair<int, int>>& vec) {
    int count = 0;
    set<pair<int, int>> st; // 1-dist 2-city
    for (int i = 0; i < vec.size(); ++i) {
        if (dist(a, i) <= k) st.insert({dist(i, b), i});
    }
    for (auto x: st) cout << x.first << " " << x.second << "\n";
    return -1;
}

int main() {
    int n;
    cin >> n;
    vec.resize(n);
    for (auto& x: vec) cin >> x.first >> x.second;
    cin >> k >> a >> b;
    if (dist(a, b) <= k) return 1;
    else cout << run(vec);
}
