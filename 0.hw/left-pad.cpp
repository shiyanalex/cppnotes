#include <iostream>

std::string leftpad(std::string str, int len, char ch = ' ') {
    if (len <= str.size()) {
        return str;
    }
    else str.insert(str.begin(), len - str.size(), ch);
    return str;
};

int main() {

    std::cout << leftpad ("foo", 3);
}

