#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>

// надо использовать бор / префиксное дерево

std::unordered_map<std::string> setter(std::string s) {
    std::unordered_map<std::string> res;

    std::string temp;
    std::stringstream dic(s);
    
    while (getline(dic, temp, ' ')) {
        res.insert(temp);
    }
    return res;
} 

int main() {

    std::string dictionary;
    std::getline(std::cin, dictionary);
    auto dicset = setter(dictionary);

    std::string text;
    std::getline(std::cin, text);
    auto txtset = setter(text);

    std::vector<std::string> ans;

    for (auto& word : txtset) {
        bool flag = false;
        for (int i = 1; i < std::min(100, (int)word.size()); ++i) {
            std::string part = word.substr(0, i);
            if (dicset.count(part)) {
                ans.push_back(part);
                flag = true;
                break;
            }
        }
        if (flag == false) ans.push_back(word);
    }

    for (auto x : ans) std::cout << x << ";";
}

