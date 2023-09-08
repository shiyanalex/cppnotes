#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// https://contest.yandex.ru/contest/50242/problems

bool func(std::vector<int>& vec, int k) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (vec[i] == vec[j] && j-i <= k) {
                return true;
            }
        }
    }
    return false;
}

bool func2(std::vector<int>& vec, int k) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        for (auto jt = it+1; jt != vec.end(); ++jt) {
            if (*it == *jt && std::distance(it, jt) <= k) {
                return true;
            }
        }
    }
    return false;
}

bool func3(std::vector<int>& vec, int k) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        auto jt = std::find(it+1, vec.end(), *it);

        if (jt != vec.end() && std::distance(it, jt) <= k) {
            return true;
        }
    }
    return false;
}

bool func4(std::vector<int>& vec, int k) {
    std::unordered_map<int, int> positions;

    for (int i = 0; i < vec.size(); ++i) {
        auto find = positions.find(vec[i]);
        if (find != positions.end() && (i - find->second) <= k) {
            return true;
        }
        else positions[vec[i]] = i;
    }
    return false;
}

int main() {

    long n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);

    for (long i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    bool flag = func3(vec, k);

    if (flag) std::cout << "YES";
    else std::cout << "NO";
}
