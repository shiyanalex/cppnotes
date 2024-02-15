#include <iostream>
#include <vector>
std::string v;

// trash
int good(int i) {
    int l = 0;
    int r = v.size() - i;

    while (l < r) {
        int m = (l+r)/2+1;
        if (v.substr(0, m) != v.substr(i, m)) r = m-1;
        else l = m;
    }
    return l;
}

void zfunc(std::string& v) {
    std::vector<int> sol(v.size(), 0);

    for (int i = 1; i < v.size(); ++i) {
        if (v[0] != v[i]);
        else sol[i] = good(i);
    }
    for (auto x : sol) std::cout << x << " ";
}

int main() {
    std::cin >> v;
    zfunc(v);
}
