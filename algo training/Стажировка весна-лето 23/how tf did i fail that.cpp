#include <iostream>
using namespace std;
// "Привет :-)))  Как дела? :-(( Отвратительно :-)))( Почему :((("
// "Привет Как дела? Отвратительно Почему"
// :-))))...
// :-(((....
// :-()

void func(string& s) {
    for (int i = 0; i + 1 < s.size(); ) {
        if (s[i] == ':' && s[i + 1] == '-') {
            int k = i + 2;
            
            if (s[k] == ')') {
                while (k < s.size() && s[k] == ')') ++k;
            }
            else if (s[k] == '(') {
                while (k < s.size() && s[k] == '(') ++k;
            }
            s.erase(i, k - i);
        }
        else {
            ++i;
        }
    }
}



int main() {
        std::string s = "Привет :-)))  Как дела? :-(()) Отвратительно :-()( Почему :((( потому :-)))(()}";
        cout << s << "\n";
        func(s);
        cout << s;
}

