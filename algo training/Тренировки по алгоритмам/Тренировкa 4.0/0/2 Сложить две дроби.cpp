#include <iostream>
using namespace std;
int a,b,c,d;
// алгоритм евклида НОД
int gcd (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    return a + b;
}

pair<int, int> solve () {
    int num = a*d + b*c;
    int den = b*d;
    int g = gcd(num, den);
    return {num/g, den/g};
}

int main() {
    cin >> a >> b >> c >> d;
    auto slv = solve();
    cout << slv.first << " " << slv.second;
}
