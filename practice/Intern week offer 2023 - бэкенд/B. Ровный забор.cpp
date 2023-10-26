#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());
    
    int window = n - k - 1;
    int diff = 1000000;

    for (int i = 0; window < n;) {
        diff = std::min(vec[window] - vec[i], diff);
        ++i;
        ++window;
    }
    std::cout << diff;

}
