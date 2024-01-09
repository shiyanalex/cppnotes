#include <iostream>
#include <sstream>
#include <vector>
#include <set>

int main() {
    int N;
    std::cin >> N;
    int res = 0;

    std::set<std::string> common;

    for (int i = 0; i < N; ++i) {
        int n;
        std::cin >> n;
        for (int j = 0; j < n; ++j) {
            std::string lang;
            std::cin >> lang;
            if (common.contains(lang)) ++res;
            else common.insert(lang);
        }
    }
    std::cout << res;

}
