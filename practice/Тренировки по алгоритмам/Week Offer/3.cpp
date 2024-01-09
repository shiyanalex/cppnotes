#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {

    int n;
    std::cin >> n;

    std::unordered_map<std::string, std::pair<int, bool>> mapper;
    for (int i = 0; i < n; ++i) {
        std::string str;
        int time;
        std::cin >> str >> time;
        auto tmp = mapper.find(str);

        if (tmp != mapper.end()) {
            if (mapper[str].second == true) {
                mapper[str].first = time - mapper[str].first;
                mapper[str].second = false;
            } else {
                mapper[str].first += time;
                mapper[str].second = true;
            }
        }
        else mapper.insert(std::make_pair(str, std::make_pair(time, true)));
    }
   for (auto x : mapper) x.second.second
    
    for (auto x : mapper) std::cout << x.first << " " << x.second.first << "\n";

}
