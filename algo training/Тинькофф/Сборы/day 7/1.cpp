#include <iostream>
using namespace std;
string vec;

void del(int i) {
    vec.erase(i-1, 1);
}

bool eq(int a, int b, int l) {
    //string s1 = vec.substr(a-1, l);
    //string s2 = vec.substr(b-1, l);
    //std::cout << s1 << " = " << s2 << "\n";
    //if(s1 == s2) return true;
    for (int i = 0; i < l; ++i) {
        if (vec[a-1] != vec[b-1]) return false;
        ++a, ++b;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::getline(cin, vec);
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        string s;
        std::getline(cin, s);
        if (s[0] == '-') {
            del(s[2]-'0');
        }
        else if (s[0] == '?') {
            if (eq(s[2]-'0', s[4]-'0', s[6]-'0')) cout << "ia\n";
            else cout << "jok\n";
        }
    }
}
