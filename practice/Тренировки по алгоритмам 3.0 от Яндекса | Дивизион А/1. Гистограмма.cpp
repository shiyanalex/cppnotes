#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>

//https://contest.yandex.ru/contest/45469/problems/

std::string read(std::string s) {
    std::fstream file;
    file.open(s);

    std::string res;

    if (file.is_open()) {
        //std::cout << "File is open : \n";
        
        while (!file.eof()) {
            std::string str;
            getline(file, str);
            res += str;
            res.erase(remove_if(res.begin(), res.end(), isspace), res.end());
        }
        return res;
        
    } else std::cout << "Error GG \n";
    return NULL;
}

void func(std::string& str) {

    int max = 0;
    std::unordered_map<char, int> mapper;

    for (const auto c : str) {
        ++mapper[c];
        if (mapper[c] > max) max = mapper[c];
    }

    for (int i = max; i != 0; --i) {
        for (auto& x: mapper) {
            if (x.second >= i) 
                std::cout << "#";
            else 
                std::cout << " ";
        }
        std::cout << "\n";
    }

    for (auto& x: mapper) std::cout << x.first;

}

int main () {

    std::string a = read("input.txt");
    func(a);
    //for (auto& x: mapper) std::cout << x.first << " " << x.second << "\n";
}

