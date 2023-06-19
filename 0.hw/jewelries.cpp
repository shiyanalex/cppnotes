#include <algorithm>
#include <iostream>
#include <vector>

// Даны две строки строчных латинских символов: строка J и строка S. Символы, входящие в строку J, 
// — «драгоценности», входящие в строку S — «камни». Нужно определить, какое количество символов 
// из S одновременно являются «драгоценностями». Проще говоря, нужно проверить, какое количество символов из S входит в J.
// ab aabbccd - 4

int main() {
    std::string j, s;
    std::cin >> j >> s;
 
    int result = 0;
    for (const char ch : s) {
        result += j.find(ch) != std::string::npos;
    }
 
    std::cout << result;
    
    return 0;
}
