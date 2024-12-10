#include <iostream>
#include <map>
using namespace std;

int32_t main() {
    int p, v, q, m;
    cin >> p >> v >> q >> m;
    map<int, bool> mapper;
    for (int i = p-v; i < p+v; ++i) mapper[i] = true;
    for (int i = q-m; i < q+m; ++i) mapper[i] = true;
    int extra = 0;
    if (p-v < 0 || q-m < 0) extra = 1;
    cout << mapper.size() + extra;
}

