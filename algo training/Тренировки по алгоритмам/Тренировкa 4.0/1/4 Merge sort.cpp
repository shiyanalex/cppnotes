#include <iostream>
#include <vector>

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

void msort(std::vector<int>& vec) {
    std::vector<int> tmp(vec.size());
    
    for (int i = 1; i < vec.size(); i*=2) { // i - size of chunk
        for (int j = 0; j < vec.size(); j+=2*i) { // start of each seq
            merge(vec[j:j+i], vec[j+i, std::min(n, j+2*i)])
        }
    
    }
    
}

int main() {
    /*
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    */
    std::vector<int> vec{1,2,3,7,9,3,4,8,12,0,5};
    msort(vec);
    for (auto& x: vec) std::cout << x << " ";

}

