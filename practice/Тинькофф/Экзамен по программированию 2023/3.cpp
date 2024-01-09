#include <iostream>
#include <vector>
#include <algorithm>

bool func(std::vector<long>& now, std::vector<long>& win) {

    for (int i = 0; i < now.size(); ++i) {

        if (now[i] != win[i]) {
            int j = i;
            while (now[j] != win[j]) {
                ++j;
            }
            auto it = now.begin() + i;
            auto it1 = now.begin() + j;
            std::sort(it, it1);
            break;
        }
    }

    if (now == win) return true;
    else return false;
}


int main() {

    long n;
    std::cin >> n;

    std::vector<long> now;
    for (long i = 0; i < n; ++i) {
        long x;
        std::cin >> x;
        now.push_back(x);
    }
    
    std::vector<long> win;
    for (long i = 0; i < n; ++i) {
        long x;
        std::cin >> x;
        win.push_back(x);
    }

    auto w = func(now, win);
    std::cout << (w ? "YES" : "NO");

}
