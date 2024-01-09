#include <iostream>
#include <vector>

template<typename T>
std::vector<T> prefix(std::vector<T>& v) {
    int n = v.size();
    std::vector<T> p(n+1);

    for (int i = 0; i < n; ++i) {
        p[i+1] = p[i] + v[i];
    }
    return p;
}

int main() {
    std::vector<int> v1{1,4,2,6,8,3,7,0,2,1};
    auto v2 = prefix(v1);

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    for (; it2!= v2.end(); ++it2) {
        std::cout << *it1 << " " << *it2 << "\n";
        ++it1;
    }
}
