#include <iostream>
#include <vector>
#include <cmath>

int mgcd(int a, int b) {
   if (b == 0)
   return a;
   return mgcd(b, a % b);
}

// WRONG!
std::pair<int, int> double_to_fraction(double x) {
    int numerator = round(x * 100);
    int denominator = 100;
    int gcd = mgcd(numerator, denominator);
    
    return std::make_pair(numerator / gcd, denominator / gcd);
}


std::pair<int, int> double_to_fraction2(double x) {

    for (int q = 1; q <= 100; ++q) {
        for (int p = 1; p <= 100 * 100+1; ++p) {
            // СНАЧАЛА УМНОЖАЕМ ПОТОМ ДЕЛИМ !!!
            if (floor(p * 100.0 / q) == round(x * 100)) {
                return std::make_pair(p, q);
            }
        }
    }
    return std::pair<int, int>();
}


std::pair<int, int> double_to_fraction3(double x) {

    for (int q = 1; q <= 100; ++q) {
        if (ceil(q*x) * 100 < round (100 * x) * q + q)
            return std::make_pair(ceil(q*x), q);
    }
    return std::pair<int, int>();
}


int main() {
    
    int n;
    std::cin >> n;

    std::vector<double> vec(n);
    for (auto& x: vec) std::cin >> x;
    std::vector<std::pair<int, int>> ans;

    for (auto& x : vec) {
        if(floor(x) == ceil(x)) ans.push_back(std::make_pair(x, 1));
        else {
            ans.push_back(double_to_fraction3(x));
        }
    }

    for (auto& x: ans) std::cout << x.first << " " << x.second << "\n";
    return 0;
}
