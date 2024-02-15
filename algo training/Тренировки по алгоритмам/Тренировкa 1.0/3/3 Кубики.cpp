#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::set<int> anna;
    std::set<int> boris;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        anna.insert(num);
    }
    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;
        boris.insert(num);
    }
    std::vector<int> intersection;
    std::set_intersection(anna.begin(), anna.end(), boris.begin(), boris.end(), std::back_inserter(intersection));
    std::cout << intersection.size() << "\n";
    for (auto x: intersection) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> diff1;
    std::set_difference(anna.begin(), anna.end(), boris.begin(), boris.end(), std::inserter(diff1, diff1.begin()));
    std::cout << diff1.size() << "\n";
    for (auto x: diff1) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> diff2;
    std::set_difference(boris.begin(), boris.end(), anna.begin(), anna.end(), std::inserter(diff2, diff2.begin()));
    std::cout << diff2.size() << "\n";
    for (auto x: diff2) std::cout << x << " ";
    return 0;
}

