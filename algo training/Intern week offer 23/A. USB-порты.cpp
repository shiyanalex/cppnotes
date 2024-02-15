#include <iostream>
#include <cmath>

// https://contest.yandex.ru/contest/50834/problems/

int main() {

    float n, m, c2, c5;
    std::cin >> n >> m >> c2 >> c5;
    int res1 = 0;
    int res2 = 0;
    m -= n;
    int m2 = m;
    n = 0;
   
    while (m > n) {
        if ((std::ceil(m/2))*c2 >= std::ceil(m/5)*c5) {
            res1 += c5;
            m -=4;
        } else {
            res1 += c2;
            m -= 1;
        }
    }

    while (m2 > n) {
        if ((std::ceil(m/2))*c2 > std::ceil(m/5)*c5) {
            res2 += c2;
            m2 -= 1;
        } else {
            res2 += c5;
            m2 -=4;
        }
    }

    std::cout << std::min(res1, res2);

}
