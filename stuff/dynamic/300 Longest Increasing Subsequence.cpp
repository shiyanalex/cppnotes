#include <iostream>
#include <vector>
#include <algorithm> // for max_element

// O(n^2) just length
int lengthOfLIS(std::vector<int>& vec) {
    int n = vec.size();
    std::vector<int> dp(n, 1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (vec[j] < vec[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

// O(n^2) sequence
std::vector<int> lis(std::vector<int>& vec) {
    int n = vec.size();
    std::vector<int> dp(n, 1);      // длина последовательности заканчивающаяся в i-ом элементе 
    std::vector<int> prev(n, -1);   // индексы для восстановления
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (vec[j] < vec[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }    

    /*
    int pos = 0;            // индекс последнего элемента НВП
    int length = dp[0];     // длина НВП
    for (int i = 0; i < n; ++i) {
        if (dp[i] > length) {
            length = dp[i];
            pos = i;
        }
    } */
    
    int pos = std::max_element(dp.begin(), dp.end()) - dp.begin();
    int length = dp[pos];

    std::vector<int> ans(length);
    for (int i = 0; i < length; ++i) {
        ans[i] = vec[pos];
        pos = prev[pos];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    //std::vector<int> vec{1,3,5,2,7,9,4,23,10};//(n);
    for (auto& x: vec) std::cin >> x;
    for (auto x: lis(vec)) std::cout << x << " ";
}

