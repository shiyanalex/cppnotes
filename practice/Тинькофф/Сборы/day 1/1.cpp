#include <iostream>
#include <vector>
#include <map>
#define ll long long

std::vector<int> run(std::vector<int>& h) {
    std::vector<int> ans(h.size());
    int iteration = 1;
    
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> hinges(q);
    for (auto& x: hinges) std::cin >> x;
    for (auto x: run(hinges)) std::cout << x << " ";
}
