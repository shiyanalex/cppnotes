#include <iostream>
#include <set>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::set<std::pair<char, char>> gens;

    for (int i = 0; i < s2.size()-1; ++i) {
        gens.insert(std::make_pair(s2[i], s2[i+1]));
    }
    //for (auto& x: gens) std::cout << x.first << " " << x.second << "\n";

    int res = 0;
    for (int i = 0; i < s1.size()-1; ++i) {
        if (gens.contains(std::pair(s1[i], s1[i+1]))) ++res;
    }
    std::cout << res;
}
