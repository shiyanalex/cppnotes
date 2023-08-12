#include <iostream>
#include <vector>
#include <map>

void checkString(std::string &s1, std::string &s2) {
    std::map<char, int> mapper;

    for (const auto c : s1) {
        ++mapper[c];
    }

    bool flag = false;
    for (int i = 0; i < s2.length(); ++i) {
        auto tmp = mapper.find(s2[i]);

        if (tmp != mapper.end()) {
            if (tmp->second > 1) {
                tmp->second--;
            } else {
                // думаю тут проблемма, но хз как исправить
                mapper.erase(tmp);
            }
        }
        else {
            flag = true;
            break;
        }
    }

    if (!mapper.empty() || flag == true) std::cout << "0";
    else std::cout << "1";
}

std::map<char, int> counter(std::string &st) {
    std::map<char, int> mapper;

    for (const auto c : st) {
        ++mapper[c];
    }
    return mapper;
}

int main() {

    std::string s1, s2;
    getline (std::cin, s1);
    getline (std::cin, s2);

    // the best solution, mem O(n/2)
    checkString(s1, s2);

    // time O(n) + mem O(n)
    /*
    auto s = counter(s1);
    auto t = counter(s2);
    if (s == t) std::cout << "1";
    else std::cout << "0";
    */
   
    // time O(n logn) и мы меняем входные данные
    /*
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    std::cout << (s1 == s2 ? 1 : 0) << std::endl;
    */
}


