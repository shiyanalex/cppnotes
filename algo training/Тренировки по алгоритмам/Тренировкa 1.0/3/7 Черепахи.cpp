#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<int> turtles;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (x >= 0 && y >= 0 && x+y == n-1 && !turtles.contains(x)) turtles.insert(x);
    }
    std::cout << turtles.size();
}
