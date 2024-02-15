#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
    int n, m;
    int g[n+1][n+1];
    //  https://new.contest.yandex.ru/50916/

void dfs(int start, vector<bool>& visited) {
    cout << start << " ";
    visited[start] = true;
 
    for (int i = 1; i < n+1; i++) {
        if (g[start][i] == 1 && (!visited[i])) {
            dfs(i, visited);
            g2[i][visited] = 1;
            g2[visited][i] = 1;
        }
    }
}

int main() {
    cin >> n >> m;
    string trash;
    std::getline(std::cin, trash);


    int g2[n+1][n+1];
    memset(g, 0, sizeof(g));
    memset(g2, 0, sizeof(g2));

    for (int i = 1; i <= m; ++i){
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int v = 0;
        int prev = 0;
        while (iss >> v) {
            if (v != prev && prev != 0) {
                g[v][prev] = 1;
                g[prev][v] = 1;
            } prev = v;
            if (v != i) {
                
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << g[i][j] << " ";
        } cout << "\n";
    }
    cout << "\n";

    vector<bool> visited(v, false);
    dfs(0, visited);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << g2[i][j] << " ";
        } cout << "\n";
    }
}   

