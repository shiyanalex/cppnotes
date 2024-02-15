#include <iostream>
#include <vector>
using namespace std;

// TL
int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    return a + b;
}

int inv(vector<int>& vec) {
    int count = 0;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i+1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) ++count;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x: vec) cin >> x;
    int total = 0;
    int permutations = 0;
    for (int i = 0; i < vec.size() - 1; ++i) {
        for (int j = i+1; j < vec.size(); ++j) {
            auto tmp = vec;
            swap(tmp[i], tmp[j]);
            total += inv(tmp);
            ++permutations;
        }
    }
    int g = gcd(total, permutations);
    cout << total/g << "/" << permutations/g;
}
