#include <iostream>
#include <vector>
#include <algorithm>

// хорошее решение через сортировку подсчетом + 2 указателя
int main() {

    int n;
    std::cin >> n;
    std::vector<int> vec(n);

    for (auto& x : vec) std::cin >> x;
    std::sort(vec.begin(), vec.end());
    
    long res = 0; //!!!
    int l = 0;
    int r = 0;
    for (auto x : vec) {
        while (l < n && double(vec[l]) <= double(x)*0.5+7) ++l;
        while (r < n && vec[r] <= x) ++r;
        if (r > l) res += r-l-1;
    }

    std::cout << res;
}

