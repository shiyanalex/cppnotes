#include <iostream>
#include <vector>
#include <map>

/*
int maxProfit(int k, std::vector<int>& prices) {
    std::vector<int> sell(k+1, 0), bought(k+1, INT_MIN);
    for(auto price: prices) {
        for(int i=k-1; i>=0; --i){
            sell[i] = std::max(sell[i], bought[i] + price);
            bought[i] = std::max(bought[i], i == 0 ? -price : sell[i-1]-price);
        }
    }

    for (auto x : sell) std::cout << x;
    //std::cout << "\n";
    //for (auto x : bought) std::cout << x;

    return sell[k-1];

} */


int main() {

    int days;
    std::cin >> days;
    std::vector<int> prices;

    for (int i = 0; i < days; ++i) {
        int x;
        std::cin >> x;
        prices.push_back(x);
    }

    std::vector<int> v;
    int imax = 0;
    int b2 = 0;
    int s2 = 0;

    for (int i = days; i > 0; --i) {
        for (int j = days - 1; j > 0; --j) {
            int temp = prices[i] - prices[j];
            if (temp > imax) {
                imax = temp;
                s2 = i + 1;
                b2 = j + 1;
            }
        }
    }

    int imin = 0;
    int b1 = 0;
    int s1 = 0;

    for (int i = 0; i < days - 1; ++i) {
        for (int j = i + 1; j < days - 1; ++j) {
            int temp = prices[j] - prices[i];
            if (temp > imin) {
                imin = temp;
                b1 = i + 1;
                s1 = j + 1;
            }
        }
    }

    std::cout << "imax " << imax << "imin " << imin << "\n";;
    std::cout << "b2 " << b2 << "b1 " << b1 << "\n";
    std::cout << "s2 " << s2 << "s1 " << s1 << "\n";



    for (int i = 0; i < days; ++i) {
    
    
    }


}
