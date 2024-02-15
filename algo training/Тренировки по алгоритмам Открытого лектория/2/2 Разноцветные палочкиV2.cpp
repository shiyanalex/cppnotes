#include <iostream>
#include <unordered_map>
#include <set>

int main() {

    std::string s;
    std::cin >> s;

    std::unordered_map<int, std::set<char>> mapper;

    for (int i = s.size()-1; i > 0;) {
        mapper[s[i]-'0'].insert(s[i-1]);
        i-=2;
    }
    
    /*
    for (auto& pair : mapper) {
        std::cout << pair.first << " -> ";
        for (const auto& char_set : pair.second) {
            std::cout << char_set << " ";
        }
        std::cout << std::endl;
    } */

    int res = 0;
    for (const auto& pair: mapper) {
        if (pair.second.size() > 2) ++res;
    }
    std::cout << res;
}
