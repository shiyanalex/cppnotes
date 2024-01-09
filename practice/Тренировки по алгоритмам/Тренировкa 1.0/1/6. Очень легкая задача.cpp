#include <iostream>
#include <vector>

int main() {

    int n, x, y;
    std::cin >> n >> x >> y;

    if (n == 1) std::cout << std::min(x, y);
    else {
        int l = 0;
        int r = n*std::max(x, y);

        while (l < r) {
            int m = (l+r)/2; // среднее время
            if (n-1 <= m/x + m/y) r = m;
            else l = m+1;
        }
        std::cout << l+std::min(x, y);
    }
}
