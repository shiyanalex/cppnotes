#include <iostream>

int sum(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += i;
    }
    return res;
}

int sum2(int n) {
    return n*(n+1)/2;
}

int sum3(int x, int& res) {
    if (x == 0) return 0;
    res += x;
    sum3(--x, res);
    return res;
}

int main() {
    int x;
    std::cin >> x;
    std::cout << sum(x) << "\n";
    std::cout << sum2(x) << "\n";
    int res = 0;
    std::cout << sum3(x, res) << "\n";
}
