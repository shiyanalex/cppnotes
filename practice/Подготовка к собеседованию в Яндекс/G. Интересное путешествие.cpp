#include <iostream>
#include <vector>
int k, a, b;
std::vector<std::pair<int, int>> vec;

int dist(int a, int b) {
    a -= 1, b -=1;
    return abs(vec[a].first - vec[b].first) + abs(vec[a].second - vec[b].second);
}

int run(std::vector<std::pair<int, int>>& vec) {
    int count = 0;
    if (a-1 == b-1) return count;
    for (auto x: vec)
    return -1;
}

int main() {
    // изи Дейкстра
    int n;
    vec.resize(n);
    for (auto& x: vec) std::cin >> x.first >> x.second;
    std::cin >> k >> a >> b;
    std::cout << run(vec);
}
