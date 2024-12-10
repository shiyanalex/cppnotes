#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void printDescendingOrder(unordered_map<int, int>& mp){
    vector<pair<int, int>> tempVec;

    for(auto &x : mp)
       tempVec.push_back({ x.second, x.first});

    sort(tempVec.begin(), tempVec.end());

    for(auto &y : tempVec)
      cout << y.first << " " << y.second << "\n";
}

// дан вектор чисел, надо найти отрезок который будет равен x. Вернуть координаты начала и конеца найденного отрезка

// O(n^2)
pair<int, int> f1(int x, vector<int>& vec) {
    if (x == 0) return {0, 0};
    int n = vec.size();
    vector<int> pref(n+1);

    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] + vec[i];
        if (pref[i+1] == x) return {0, i+1};

        for (int j = 0; j < i; ++j) {
            if (pref[i+1] - pref[j] == x) return {j, i+1};
        }
    }
    return {-1, -1};
}

// O(n)
// WA
pair<int, int> f2(int x, vector<int>& vec) {
    if (x == 0) return {0, 0};
    unordered_map<int, int> mapper;
    int pref = 0;

    for (int i = 0; i < vec.size(); ++i) {
        pref += vec[i];
        if (pref == x) return {0, i+1};
        if (mapper.count(pref-x)) return {mapper[pref-x], i+1};
        mapper[pref] = i+1;
    }
    //printDescendingOrder(mapper);
    return {-1, -1};
}

void run(int target, vector<int>& nums) {
    auto ans = f1(target, nums);
    auto ans2 = f2(target, nums);
    cout << ans.first << " " << ans.second << "\n";
    //cout << ans2.first << " " << ans2.second;
}

int main() {
    vector<int> nums = {1,4,6,-5,8,3,5,1,9};
    int t; cin >> t;
    run(t, nums);
}
