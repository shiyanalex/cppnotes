#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//https://contest.yandex.ru/contest/50340/problems/

int main() {

    int n;
    std::cin >> n;
    std::vector<int> vec(n+1, 0);
    int now = 0;
    for (int i = 1; i < n+1; ++i) {
        int x;
        std::cin >> x;
        if (x > 0) ++now;
        vec[i] = now;
    }
   
    int q;
    std::cin >> q;
    //std::vector<int> res(q);

    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        //res[i] = vec[r] - vec[l-1];
        std::cout << vec[r] - vec[l-1] << " ";
    }
    //for (auto x : res) std::cout << x << " ";
}

