#include <iostream>
#include <cmath>
#include <chrono>

using namespace std::chrono;

int fifth1(int n) {
    int sum = 0;

    std::string str = std::to_string(n);
    for (char c : str) {
        int digit = c - '0';
        sum += std::pow(digit, 5);
    }
    return sum;
}

int fifth2(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        sum += std::pow(digit, 5);
    }
    return sum;
}

void compute() {
    int result = 0;
    
    auto start = high_resolution_clock::now();

    for (int i = 2; i < 1000000; ++i) {
        if (i == fifth1(i)) {
            //std::cout << i << "\n";
            result += i;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "time1 : " << duration.count() << "ms" << std::endl;
    std::cout << result; //std::to_string(result);
    result = 0;

    start = high_resolution_clock::now();

    for (int i = 2; i < 1000000; ++i) {
        if (i == fifth2(i)) {
            //std::cout << i << "\n";
            result += i;
        }
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    std::cout << "\ntime2 : " << duration.count() << "ms" << std::endl;
    std::cout << result;
}

int main() {

    compute();

}

