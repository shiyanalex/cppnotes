#include <iostream>
#include <algorithm>

std::string isPal(std::string S) {
    for (auto & c : S) {
        c = tolower(c);
        std::erase(S, ' ');
    } 
    std::cout << S << "\n";
    std::string P = S;
    std::reverse(P.begin(), P.end());

    if (S == P) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    std::string str = "ape ePa";
    /*
    std::string str;    
    getline (std::cin, str);
    */
    std::cout << isPal(str);
}
