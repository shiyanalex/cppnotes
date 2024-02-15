#include <iostream>

//https://contest.yandex.ru/contest/50158/problems/A/

int main() {

    int x = 0;
    std::cin >> x;
    int y = 1;
    int res = 0;
    
    for (int i = 0; i < x; ++i) {
        if (x >= y) {
            x -= y;
            ++y;
            ++res;
        }
    }
    std::cout << res;

}
