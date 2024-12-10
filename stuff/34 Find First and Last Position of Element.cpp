#include <iostream>
#include <vector>
using namespace std;
// # of same element in vector

int lsearch(std::vector<int>& vec, int key) {
    int l = 0;
    int r = vec.size();
    while (l < r) {
        int mid = (l+r)/2;
        if (vec[mid] == key) return key;
        else if (vec[mid] > key) r = mid;
        else l = mid+1;
    }
    return l;
}

int rsearch(std::vector<int>& vec, int x) {
    int l = 0;
    int r = vec.size();
    bool flag = false;
    
    while (l < r && flag == false) {
        int m = (l+r+1)/2;
        if (vec[m] == x) flag = true;
        if (vec[m] < x) l = m;
        else r = m-1;
    }
    return l;
}

std::pair<int, int> run(std::vector<int>& vec, int x) {
    
    if (find(vec.begin(), vec.end(), x) != vec.end()) {
        auto upper = upper_bound(vec.begin(), vec.end(), x) - vec.begin();
        auto lower = upper_bound(vec.begin(), vec.end(), x-1) - vec.begin();
        return {lower, upper-1};
    }
    else return {-1, -1};
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (find(nums.begin(), nums.end(), target) != nums.end()) {
        auto upper = (int)(upper_bound(nums.begin(), nums.end(), target) - nums.begin());
        auto lower = (int)(upper_bound(nums.begin(), nums.end(), target-1) - nums.begin());
        vector<int> ans = {lower, upper-1};
        return ans;
    }
    else return {-1, -1};
}

int main() {
    std::vector<int> v {5,7,7,8,8,10};
    std::sort(v.begin(), v.end());
    for (auto& x: v) std::cout << x << " ";
    std::cout << "\n";
    //auto ans = run(v, 8);
    //cout << ans.first << " " << ans.second;
    for (auto x: searchRange(v, 11)) cout << x << " ";
}

