#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;

int lsearch(int x) {
    int l = 0;
    int r = vec.size();
    if (x >= *(vec.end()-1)) return *(vec.end()-1);
    while (l < r) {
        int m = (l+r)/2;
        if (vec[m] == x) return x;
        else if (vec[m] > x) r = m;
        else l = m+1;
    }
    return vec[l];
}

int rsearch(int x) {
    int l = 0;
    int r = vec.size();
    while (l < r) {
        int m = (l+r+1)/2;
        if (vec[m] == x) return x;
        else if (vec[m] < x) l = m;
        else r = m-1;
    }
    return vec[r];
}


int main() {
    int n, k;
    std::cin >> n >> k;
    vec.resize(n);
    for (auto& x: vec) cin >> x;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        //cout << lsearch(x) << " " << rsearch(x) << "\n";
        int l = lsearch(x);
        int r = rsearch(x);
        //cout << l << " " << r << " ";
        abs(x-l) < abs(x-r) ? cout << l : cout << r;
        cout << "\n";
    }
}
