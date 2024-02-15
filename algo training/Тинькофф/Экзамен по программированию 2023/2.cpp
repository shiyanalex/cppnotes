#include <iostream>
#include <unordered_map>
#include <set>

int main() {

    std::string s;
    std::cin >> s;

    int res = 0;
    std::string sheriff = "sheriff";

    std::unordered_map<char, int> mapper;

    
    for (int i = 0; i < s.size(); ++i) {
        if (mapper.find(s[i]) == mapper.end()) {
            mapper.insert(std::make_pair(s[i], 1));
        } else ++mapper[s[i]];
    }
    
    /*
    for (int i = 0; i < s.size(); ++i) {
        for (int i = 0; i < sheriff.size(); ++i) {
            if (s.find(sheriff[i]) != std::string::npos) {
            } else break;
            res += 1;
        } 
    } */

    bool flag = true;

    for (int i = 0; i < s.size(); ++i) {

        for (int i = 0; i < sheriff.size(); ++i) {
            auto tmp = mapper.find(sheriff[i]);
            if (tmp != mapper.end() && tmp->second > 0) {
                --tmp->second;
            } else {
                flag = false;
                break;
            }
        } if (flag) ++res;
    }

    /*
    for (auto& pair : mapper) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    } */

    std::cout << res;

}
