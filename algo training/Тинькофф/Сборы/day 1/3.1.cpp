#include <iostream>
#include <queue>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec) std::cin >> x;
    std::priority_queue<int> pq;
    for (auto x: vec) pq.push(x);
    for (auto x: vec) std::cout << x << " ";
    std::cout << "\n";
    while (!pq.empty()) {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
}
