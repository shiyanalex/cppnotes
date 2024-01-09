#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//  https://new.contest.yandex.ru/53991/statistics

int main() {

    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& v: vec) std::cin >> v;

    auto it1 = vec.begin();
    auto it2 = vec.rbegin();
    auto mid = vec.begin() + vec.size();
    int num = *it1 + *it2;
    
    bool flag = true;
    for (; it1 != mid; ++it1, ++it2) {
        if (*it1 + *it2 != num) {
            flag = false;
            break;
        }
    }

    if (flag) std::cout << num;
    else std::cout << -1;

}
