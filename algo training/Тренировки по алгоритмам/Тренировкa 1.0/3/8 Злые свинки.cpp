#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<int> points;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        points.insert(x);
    }
    std::cout << points.size();
}
