#include <iostream>
#include <vector>
#include <map>

// O(n log(n/2))?
bool run(std::string& s1, std::string& s2) {
    if (s1.size() != s2.size()) return false;
    std::map<char, int> mapper;
    for (const auto c: s1) ++mapper[c];

    bool flag = false;
    for (int i = 0; i < s2.length(); ++i) {
        auto tmp = mapper.find(s2[i]);
        if (tmp != mapper.end() && tmp->second >= 1) tmp->second--;
        else return false;
    }
    return true;
}

std::map<char, int> count(std::string& str) {
    std::map<char, int> mapper;
    for (const auto c : str) ++mapper[c];
    return mapper;
}

int main() {
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    std::cout << run(s1, s2);
    // O(n log(n))
    /*
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    std::cout << (s1 == s2 ? 1 : 0) << std::endl;
    */

    // time O(n) + mem O(n)
    /*
    auto s = count(s1);
    auto t = count(s2);
    if (s == t) std::cout << "1";
    else std::cout << "0";
    */
}

