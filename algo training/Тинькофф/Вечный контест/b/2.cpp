#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool bestSum(int target, const std::vector<int>& nums) {
    if (target == 0) return true;
    else if (target < 0) return false;
    
    for (auto x: nums) {
        int remainder = target - x;
        if (bestSum(remainder, nums) == true) {
            ans.push_back(x);
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
    int n, t;
    cin >> n >> t;

    map<int, int> mapper;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        mapper[a] = b;
    }
    
    int res = 0;
    int curr = 0;
    while (t > 0) {
        unordered_map<int, int> tmp;
        int min = INT_MAX;
        for (auto x: vec) {
            int val = abs(curr, x.first) + x.second
            tmp.push_back(x.first, );
            min = min(min, abs(curr, x.first) + x.second)
        }
    }
    cout << res;

}
