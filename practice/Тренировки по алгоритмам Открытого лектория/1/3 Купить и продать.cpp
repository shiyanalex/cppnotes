#include <iostream>
#include <vector>

// Купить и продать

int main() {

    int days;
    std::cin >> days;
    std::vector<int> prices;

    for (int i = 0; i < days; ++i) {
        int x;
        std::cin >> x;
        prices.push_back(x);
    }

    // тут я искал наибольшую разницу в цене, видимо это неверно

    /*
    int max = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < days; ++i) {
        for (int j = i + 1; j < days; ++j) {
            int temp = prices[j] - prices[i];
            if (temp > max) {
                max = temp;
                x = i + 1;
                y = j + 1;
            }
        }
    }
    */

    int bday = 0;
    int sday = 0;
    int mincostday = 0;

    for (int i = 0; i < days; ++i) {
        if (prices[sday] * prices[mincostday] < prices[bday] * prices[i]) {
            bday = mincostday;
            sday = i;
        }
        if (prices[i] < prices[mincostday]) {
            mincostday = i;
        }
    }
    
    if (bday == 0 && sday == 0) {
        std::cout << 0 << " " << 0;
    } else {
        std::cout << bday + 1 << " " << sday + 1; 
    }
}
