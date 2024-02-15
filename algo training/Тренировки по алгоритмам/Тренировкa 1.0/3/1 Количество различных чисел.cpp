#include <iostream>
#include <set>
#include <sstream>

// https://contest.yandex.ru/contest/27663/problems/
// https://contest.yandex.ru/contest/27665/problems/
// https://contest.yandex.ru/contest/27794/problems/
// https://contest.yandex.ru/contest/27844/problems/
// https://contest.yandex.ru/contest/27883/problems/
// https://contest.yandex.ru/contest/28069/problems/

int main() {

    std::string s;
    getline(std::cin, s);
    std::set<int> setter;

    std::istringstream is(s);
    int in;

    while(is >> in) {
        setter.insert(in);
    }

    std::cout << setter.size();
}
