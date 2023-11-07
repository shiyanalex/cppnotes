#include <iostream>
#include <vector>
#include <sstream>
#include <map>

bool canSum(int target, std::vector<int> vec) {
    if (target == 0) return true;
    if (target < 0) return false;
    
    for (auto x: vec) {
        int remainder = target - x;
        if (canSum(remainder, vec) == true) return true;
    }
    return false;
}

bool sum_helper(int target, std::vector<int> vec, std::map<int, bool>& dp) {
    if (target == 0) return true;
    if (target < 0) return false;
    if (dp.find(target) != dp.end()) return dp[target];

    for (auto x: vec) {
        int remainder = target - x;
        if (sum_helper(remainder, vec, dp) == true) return true;
        //dp[remainder] = true; // оно тут надо вообще...?
    }
    dp[target] = false;
    return false;
}

bool canSum2(int target, std::vector<int> vec) {
    std::map<int, bool> dp;
    return sum_helper(target, vec, dp);
}

int main() {
    
    //int target, n;
    //std::cin >> target >> n;

    //fucking c++
    /*
    std::string s;
    getline(std::cin, s);
    std::vector<int> vec;
    std::istringstream is(s);
    int in;

    while(is >> in) {
        vec.push_back(in);
    }
    */

    //std::vector<int> vec(n);
    //for (auto& x: vec) std::cin >> x;
    //std::cout << canSum(target, vec);
    std::vector<int> v1{2, 3};
    std::cout << canSum(7, v1) << "\n";
    std::cout << canSum(7, std::vector<int> {5, 3, 4, 7}) << "\n";
    std::cout << canSum(7, std::vector<int> {2, 4}) << "\n";
    std::cout << canSum(7, std::vector<int> {2, 3, 5}) << "\n";
    //std::cout << canSum(300, std::vector<int> {7, 14}) << "\n";
    std::cout << "\n";
    std::cout << canSum2(7, v1) << "\n";
    std::cout << canSum2(7, std::vector<int> {5, 3, 4, 7}) << "\n";
    std::cout << canSum2(7, std::vector<int> {2, 4}) << "\n";
    std::cout << canSum2(7, std::vector<int> {2, 3, 5}) << "\n";
    std::cout << canSum2(300, std::vector<int> {7, 14}) << "\n";
}
