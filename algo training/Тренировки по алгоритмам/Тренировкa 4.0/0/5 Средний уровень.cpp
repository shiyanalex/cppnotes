#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
vector<int> run(vector<int>& vec) {
    vector<int> ans(vec.size());
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans.size(); ++j) {
            ans[i] += abs(vec[j] - vec[i]);
        }
    }
    return ans;
}

// O(n)
vector<int> run2(vector<int>& vec) {
    int n = vec.size();
    vector<int> ans(n);
    vector<int> area(n+1);
    for (int i = 0; i < n; ++i) {
        area[i+1] = vec[i] + area[i];
    }
    // bottom + top
    for (int i = 0; i < n; ++i) {
        ans[i] = ((i+1)*vec[i] - area[i+1]) + (area[n] - area[i+1] - vec[i]*(n-i-1));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x: vec) cin >> x;
    for (auto x: run(vec)) cout << x << " ";
    cout << "\n";
    //cout << vecsum(vec, 1, 3);
    for (auto x: run2(vec)) cout << x << " ";
}
