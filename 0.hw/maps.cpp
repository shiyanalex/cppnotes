#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

// равносильно
void checkString(std::string s1, std::string s2) {
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

std::map<char, int> counter(std::string &st) {
    std::map<char, int> mapper;

    for (const auto c : st) {
        ++mapper[c];
    }
    return mapper;
}

int main() {
    
    std::map<int, std::pair<int, std::string>> mp;

    mp.insert(std::make_pair(1, std::make_pair(2, "cat")));
    mp.insert(std::make_pair(2, std::make_pair(1, "dog")));
    mp.insert(std::make_pair(3, std::make_pair(5, "lizard")));

    for (int i = 0; i < mp.size(); ++i) { 
        std::cout << "Index " << i << " Quantity " << mp[i].first << " Pet " << mp[i].second << "\n";
    }

    std::unordered_map<std::string, int> mymap;
 
    mymap = { { "Australia", 1},
              { "U.S.", 2},
              { "France", 3} };

 
    for (auto it = mymap.begin(); it != mymap.end(); ++it) std::cout << it->first << " " << it->second << "\n";

}  
