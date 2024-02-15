#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;

int fiblen (int n, int& len) {
    len += 1;
    if (n == 0 || n == 1) {
        std::cout << len-- << " ";
        return 1;
    } else {
        //auto ans = fib(n-2, len) + fib(n-1, len);
        auto ans = fiblen(n-1, len) + fiblen(n-2, len);
        --len;
        return ans;
    }
}

int fib1 (int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib1(n-1) + fib1(n-2);;
    }
}

int fib2 (int n, std::vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] == 0) dp[n] = fib2(n-1, dp) + fib2(n-2, dp);
    return dp[n];
}

int main() {

    int x;
    std::cin >> x;
    auto start = high_resolution_clock::now();
    std::cout << fib1(x);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << " time1 : " << duration.count() << "ms" << std::endl;

    auto start2 = high_resolution_clock::now();
    std::vector<int> dp(x+1, 0); // why x+1?
    dp[0] = dp[1] = 1;
    std::cout << fib2(x, dp);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    std::cout << " time2 : " << duration2.count() << "ms" << std::endl;


}
