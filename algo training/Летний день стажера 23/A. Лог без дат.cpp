#include <iostream>
#include <vector>

// https://contest.yandex.ru/contest/50515/problems/

int f(std::vector<int>& mi) {
    int days = 0;
    for (int i = 0; i < mi.size(); i++){
        if (mi[i] >= mi[i+1]) ++days;
        //if (mi[i] == 0) ++days;
    }
    return days;
}

int main() {
    int n;
    std::cin >> n;
    int h, m, s = 0;
    std::vector<int> t;

    for (int i = 0; i < n; ++i) {
        std::string time;
        std::cin >> time;
        if (sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s) >= 2) {
            int sec = h*3600 + m*60 + s;
            t.push_back(sec);
        }
    }
    std::cout << f(t);    
}

