#include <iostream>
#include <vector>

// https://contest.yandex.ru/contest/27844/problems/

bool lsearch(int x, std::vector<int>& vec) {
    int l = 0;
    int r = vec.size();
    bool flag = false;

    while (l < r && flag == false) {
        int m = (l+r)/2;
        if (vec[m] == x) flag = true;
        else if (vec[m] > x) r = m;
        else l = m+1;
    }
    if (flag) return true;
    else return false;
}

int main() {

    int n, k;
    std::cin >> n >> k;
    std::vector<int> vec1(n);
    std::vector<int> vec2(k);

    for (int i = 0; i < n; ++i) {
        std::cin >> vec1[i];
    }

    for (int i = 0; i < k; ++i) {
        std::cin >> vec2[i];
    }

    for (int i = 0; i < k; ++i) {
        if (lsearch(vec2[i], vec1)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}

