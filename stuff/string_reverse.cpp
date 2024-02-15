#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string reverser(std::string& s) {
    std::string res = s;
    std::vector<int> cap;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] > 64 && s[i] < 91) cap.push_back(i);
        res[i] = tolower(res[i]);
    }

    for (int i = 0; i < res.size(); ++i) {
        int l = i;
        while ((res[i] > 96 && res[i] < 123) || (res[i] > 47 && res[i] < 58)) ++i; //будем отражать только буквы и цифры
        std::string tmp = res.substr(l, i-l);
        std::reverse(tmp.begin(), tmp.end());
        res.replace(l, i-l, tmp);
    }

    for (auto i: cap) {
        if (res[i] > 96) res[i] = toupper(res[i]);
    }
    return res;
}

int main() {
    std::string s;
    getline(std::cin, s);
    std::cout << reverser(s);
    return 0;
}


