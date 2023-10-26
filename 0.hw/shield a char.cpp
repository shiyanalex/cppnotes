#include <iostream>
#include <vector>

// экранировать / shield d letter in string

std::string mark(const std::string& str, char c) {
    std::string ans = str;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == c) {
            ans.insert(i - 1, "||");
            ans.insert(i + 1, "||");
        }
    }
    return ans;
}

int main() {
    
    std::string S = "abrakadabrasexdoll";
    std::cout << mark(S, 'd') << "\n";
    std::cout << S;

}
