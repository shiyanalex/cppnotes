#include <iostream>
using namespace std;

bool check(int n, int a, int b) {
    int rem = n % a;
    int buckets = n / a;
    if (rem == 0) return true;
    else if (rem % buckets == 0 && a + rem / buckets < b) return true;
    else if (rem % buckets > 0 && a + rem / buckets < b-1) return true;
    else return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, a, b;
        cin >> n >> a >> b;
        check(n, a, b+1) ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}
