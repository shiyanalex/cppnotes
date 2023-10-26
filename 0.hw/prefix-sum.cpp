#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


int main() {

    std::vector<int> vec{1,4,2,6,8,3,7,0,2,1};

    int n = vec.size();
    std::vector<int> v2(n+1, 0);
    for (int i = 1; i < n+1; ++i) {
        v2[i] = v2[i-1] + vec[i-1];
    }

    auto it1 = vec.begin();
    auto it2 = v2.begin();
    for (; it2!= v2.end(); ++it2) {
        std::cout << *it1 << " " << *it2 << "\n";
        ++it1;
    }
}
