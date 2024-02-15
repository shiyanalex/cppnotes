#include <iostream>
#include <vector>
#include <climits>

template <typename T>
std::vector<T> merge(std::vector<T>& v1, std::vector<T>& v2) {
    std::vector<T> res(v1.size() + v2.size());

    v1.push_back(INT_MAX);
    v2.push_back(INT_MAX);
    auto it1 = v1.begin();
    auto it2 = v2.begin();

    for (auto x = res.begin(); x != res.end(); ++x) {
        if (*it1 > *it2) {
            *x = *it2;
            ++it2;
        } else {
            *x = *it1;
            ++it1;
        }
    }
    return res;
}


int main() {

    int n;
    std::cin >> n;
    std::vector<int> v1(n);
    for (auto& v: v1) std::cin >> v;

    std::cin >> n;
    std::vector<int> v2(n);
    for (auto& v: v2) std::cin >> v;

    for (int x : merge(v1, v2)) std::cout << x << " ";

}

