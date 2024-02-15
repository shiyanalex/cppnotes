#include <iostream>
using namespace std;
// "Привет :-)))  Как дела? :-(( Отвратительно :-)))( Почему :((("
// "Привет Как дела? Отвратительно Почему"
// :-))))...
// :-(((....
// :-()

void func(string& s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ':' && s[i+1] == '-') {
            int k = i+2;
            if (s[k] == ')') while (s[k] == ')') ++k;
            else if (s[k] == '(') while (s[k] == '(') ++k;
            s.erase(i, k-i); // potentially UB, but fuk it gucci mane
        }
    }
}

int main() {
    std::string s = "Привет :-)))  Как дела? :-(()) Отвратительно :-()( Почему :((( потому :-)))(()}";
    cout << s << "\n";
    func(s); cout << s;
}

