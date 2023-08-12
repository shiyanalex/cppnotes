#include <iostream>
#include <vector>
#include <map>

// https://contest.yandex.ru/contest/44525/problems/A

int main() {

    int n;
    std::cin >> n;

    std::vector<int> alphabet;
    std::vector<int> rows;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        alphabet.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        rows.push_back(x);
    }

    int k;
    std::cin >> k;
    std::vector<int> essay;

    for (int i = 0; i < k; ++i) {
        int x;
        std::cin >> x;
        essay.push_back(x);
    }

    std::map<int, int> mapper;

    for (int i = 0; i < n; ++i) {
        mapper[alphabet[i]] = rows[i];
    }
    
    int counter = 0;

    for (int i = 0; i < essay.size() - 1; i++) {

        if (mapper[essay[i]] != mapper[essay[i + 1]]) {
            ++counter;
        }
    }
    
    std::cout << counter;
}
