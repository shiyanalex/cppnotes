#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    int total = 0;
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] - 64 << "\n";
        total += s[i] - 64;
    }
    int x = round( (total + s.size()-1) / s.size());

    cout << total << " " << x << " " << char(x+64);

}
