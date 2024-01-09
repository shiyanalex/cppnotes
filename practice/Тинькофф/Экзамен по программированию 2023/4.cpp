#include <iostream>
#include <vector>

// WA

bool hasSum(const std::vector<int>& nums, int x) {
    if (nums.size() == 0) return false;

    for (int i = nums.size(); i > 0 ; --i) {
        
        if (nums[i] == x) {
            std::cout << "SEX";
            return true;
        }

        int sum = nums[i];
        std::vector<int> res;
        res.push_back(nums[i]);

        for (int j = i-1; j > 0; --j) {
            sum += nums[j];
            res.push_back(nums[j]);
            if (sum == x) {
                std::cout << res.size() << "\n";

                for (auto x : res) std::cout << x << " ";
                return true;
            }
        }
        res.clear();
    }
    
    return false;
}

int main() {

    int n, m;
    std::vector<int> a;

    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int ai;
        std::cin >> ai;
        a.push_back(ai);
        a.push_back(ai);
    }

    if (!hasSum(a, n)) std::cout << -1;

}
