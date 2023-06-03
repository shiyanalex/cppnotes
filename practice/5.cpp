#include <iostream>
#include <unordered_map>

/*
     #    
     # #  
##########
r !,wldoeH%
*/

int main () {

    std::string S = "Hello, world!";
    
    std::unordered_map<char, int> map;

    for (int i = 0; i < S.length(); i++) {
        if (map.find(S[i]) == map.end()) {
            map.insert(std::make_pair(S[i], 1));
        } else {
            map[S[i]]++;
        }
    }

    int max = 0;

    for(const std::pair<const char, int>& n : map) {
        if (n.second > max) max = n.second;
    }
    
    int cmax = max;
    
    for (int i = 0; i < max; ++i) {
        for (auto it : map) {
            if (it.second >= cmax) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        cmax--;
        std::cout << "\n";
    }

    for(const std::pair<const char, int>& n : map) {
        std::cout << n.first;
    }


    //auto print = [](const auto& key, const auto& value) {
    //    std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    //};

    //for(const std::pair<const char, int>& n : map)
    //    print(n.first, n.second);
    //std::cout << max;

}


