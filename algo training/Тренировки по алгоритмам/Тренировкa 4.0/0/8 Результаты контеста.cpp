#include <iostream>
using namespace std;
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    if (a > (b+n-1)/n) cout << "YES";
    else cout << "NO";
}
