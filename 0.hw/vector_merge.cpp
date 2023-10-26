#include <iostream>
#include <vector>
#include <algorithm>

void merge1(std::vector<int>& v, std::vector<int>& vv, std::vector<int>& m) {
    m.reserve(v.size() + vv.size());
    m = v;
    for (int x : vv) m.push_back(x);
    sort(m.begin(), m.end());
}

template <typename T>
std::vector<T> merge2(std::vector<T>& v1, std::vector<T>& v2) {
    std::vector<T> res(v1.size() + v2.size(), 0);

    auto it1 = v1.begin();
    auto it2 = v2.begin();

    for (auto x = res.begin(); x != res.end(); ++x) {
        if (*it1 < *it2) {
            *x = *it1;
            ++it1;
        } else if (*it1 > *it2) {
            *x = *it2;
            ++it2;
        } else {
            *x = *it1;
            ++x;
            *x = *it1;
            ++it1;
            ++it2;
        }
    }
    return res;
}

int main() {

    std::vector<int> v1{1,2,5,9};
    std::vector<int> v2{3,4,5,6,8,9};
    
    std::vector<int> res;
    std::vector<int> res2;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(res));
    merge1(v1, v2, res2);

    for (int x : res) std::cout << x << " ";
    std::cout << "\n";
    for (int x : res2) std::cout << x << " ";
    std::cout << "\n";
    for (int x : merge2(v1, v2)) std::cout << x << " ";

}

