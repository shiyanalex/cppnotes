#include <iostream>
#include <vector>

int main() {
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec;
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x > 0) vec.push_back(x);
    }

    //for (auto& x : vec) std::cout << x << " ";
    //std::cout << "\n";

    int ans = 0;
    int sz = vec.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = i+1; j < sz; ++j) {
            ans += vec[i] + vec[j];
        }
        ans += vec[i];
    }
    
    std::cout << ans;
}

