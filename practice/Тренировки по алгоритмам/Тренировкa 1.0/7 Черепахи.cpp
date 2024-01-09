#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<int> turtles;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (x >= 0 && y >= 0 && x+y == n-1 && !turtles.contains(x)) ++res, turtles.insert(x);
    }
    std::cout << res;
}
