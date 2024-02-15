#include <iostream>
#include <vector>
#include <unordered_map>

struct Sticks {
    bool Red = false;
    bool Green = false;
    bool Blue = false;

    bool full(){
        if (Red && Green && Blue) return true;
        else return false;
    }
};

int main() {
    
    std::string s;
    std::cin >> s;

    std::vector<char> chars;
    std::vector<int> num;

    for (int i = 0; i < s.size();) {
        chars.push_back(s[i]);
        num.push_back(s[i+1]-'0');
        i+=2;
    }

    std::unordered_map<int, Sticks> mapper;

    for (int i = 0; i < chars.size(); ++i) {
        if (chars[i] == 'R') {
            mapper[num[i]].Red = true;
        }
        if (chars[i] == 'G') {
            mapper[num[i]].Green = true;
        }
        if (chars[i] == 'B') {
            mapper[num[i]].Blue = true;
        }
    }
    
    int res = 0;
    for (auto& pair : mapper) {
        if (pair.second.full()) ++res;
    }
    std::cout << res;
}
