#include <iostream>
#include <vector>
#include <map>

int i = 1;
int j = 1;
std::vector<int> tmp;
std::vector<std::vector<int>> ans;

bool howSum(int target, const std::vector<int>& nums) {
    tmp.clear();
    if (target == 0) return true;
    if (target < 0) return false;
    
    for (auto& x: nums) {
        int remainder = target - x;
        if (howSum(remainder, nums) == true) {
            tmp.push_back(x);
            //return true;
        }
    }
    return false;   // not possible
}

void call(int a, std::vector<int> v1) {
    howSum(a, v1);
    std::cout << i << "| ";
    
    auto& smallest = *std::min_element(ans.begin(), ans.end(),
        [](std::vector<int> const& a, std::vector<int> const& b) {
            return a.size() < b.size();
        }
    );

    for (auto& x: smallest) std::cout << x << " ";
    std::cout << "\n";
    ++i;
}

int main() {
    call(7, std::vector<int> {2, 3});
    call(7, std::vector<int> {5, 3, 4, 7});
    call(7, std::vector<int> {2, 4});
    call(8, std::vector<int> {2, 3, 5});
    //call(300, std::vector<int> {7, 14});
}
