#include <iostream>
#include <set>

int main() {
    int x, y, z, N;
    std::cin >> x >> y >> z >> N;

    std::set<int> nums;
    nums.insert(x);
    nums.insert(y);
    nums.insert(z);

    int res = 0;
    while (N > 0) {
        int digit = N % 10;
        N /= 10;
        if (!nums.contains(digit)) nums.insert(digit), ++res;
    }
    std::cout << res;
}
