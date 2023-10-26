#include <iostream>
#include <unordered_map>
#include <set>

int main() {

    int n, a, b;
    std::cin >> n >> a >> b;

    std::unordered_map<int, std::set<int>> mapper;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        mapper[x].insert(y);
    }

    for (auto& pair : mapper) {
        std::cout << pair.first << " -> ";
        for (const auto& char_set : pair.second) {
            std::cout << char_set << " ";
        }
        std::cout << std::endl;
    }

}
