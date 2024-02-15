#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

/*
void checkString(std::string& s1) {
        std::map<char, int> mapper;

        for (int i = 0; i < s1.length(); ++i) {
            auto tmp = mapper.find(s1[i]);

            if (tmp != mapper.end()) {
                tmp->second++;
            }
            else mapper.insert(std::make_pair(s1[i], 1));
        }
        for (auto x : mapper) std::cout << x.first << " " << x.second << "\n";
}
*/

std::map<char, int> counter(std::string& st) {
    std::map<char, int> mapper;

    for (const auto c : st) {
        ++mapper[c];
    }
    return mapper;
}

int main() {

    int n;
    std::cin >> n;
    std::unordered_map<int, std::set<int>> mapper;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        mapper[x].insert(y);
    }

    for (auto& pair : mapper) {
        std::cout << pair.first << " -> ";
        for (const auto& chars : pair.second) {
            std::cout << chars << " " << "\n";
        }
    }

}
