#include <iostream>
#define int long long
using namespace std;

int32_t main() {
    int l, r;
    cin >> l >> r;

    int count = 0;
    for (int i = 1; i <= 9; ++i) {
        int num = i;
        while (num <= r) {
            if (num >= l) ++count; // cout << num << "\n";
            num = num * 10 + i;
        }
    }
    cout << count;
}

