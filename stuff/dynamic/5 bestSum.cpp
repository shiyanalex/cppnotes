#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
vector<int> best;
// same as variation, but TOP DOWN

bool bestSum(int target, const std::vector<int>& nums) {
    if (target == 0) return true;
    else if (target < 0) return false;
    
    for (auto x: nums) {
        int remainder = target - x;
        if (bestSum(remainder, nums) == true) {
            ans.push_back(x);
            //if (ans.size() != 0 || ans.size() < best.size()) best = ans, ans.empty();
            return true;
        }
    }
    return false;
}

void call(int a, std::vector<int> vec) {
    bestSum(a, vec);
    for (auto x: ans) cout << x << " ";
    cout << "\n";
}

int main() {
    call(7, {5, 3, 4, 7}); // 7
    call(8, {2, 3, 5});    // 3 5
    call(8, {1, 4, 5});    // 4 4
    call(100, {2, 3, 5});    
}
