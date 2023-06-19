#include <iostream>
#include <vector>

// Купить и продать
// WA on 5th test

int main() {

    int day;
    std::cin >> day;
    std::vector<int> price;

    for (int i = 0; i < day; ++i) {
        int x;
        std::cin >> x;
        price.push_back(x);
    }

    int max = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < price.size(); ++i) {
        for (int j = i + 1; j < price.size(); ++j) {
            int temp;
            temp = price[j] - price[i];
            if (temp > max) {
                max = temp;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    std::cout << x << " " << y; 

}
