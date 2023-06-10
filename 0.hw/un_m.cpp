#include <iostream>
#include <vector>
#include <unordered_map>

int main() {

    std::unordered_map<std::string, int> mymap;
 
    mymap = { { "Australia", 1},
              { "U.S.", 2},
              { "France", 3} };

 
    for (auto it = mymap.begin(); it != mymap.end(); ++it) std::cout << it->first << " " << it->second << "\n";

}  
