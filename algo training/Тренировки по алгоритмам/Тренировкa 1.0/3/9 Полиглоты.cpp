#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<set<string>> vec(n);
    int max = 0;
    int maxi;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        if (m > max) max = m, maxi = i;
        for (int j = 0; j < m; ++j) {
            string lang;
            cin >> lang;
            vec[i].insert(lang);
        }
    }
    set<string> common = vec[0];
    for (auto x: vec) {
        set<string> temp;
        set_intersection(common.begin(), common.end(), x.begin(), x.end(), inserter(temp, temp.begin()));
        common = temp;
    }
    cout << common.size() << "\n";
    for (auto x: common) cout << x << "\n";
    
    /* READ CAREFULLY!!!
    cout << max << "\n";
    for (auto x: vec[maxi]) cout << x << "\n";
    */
    
    set<string> all = vec[0];
    for (auto x: vec) {
        set<string> temp;
        set_union(all.begin(), all.end(), x.begin(), x.end(), inserter(temp, temp.begin()));
        all = temp;
    }
    std::cout << all.size() << "\n";
    for (auto x: all) cout << x << "\n";
}

