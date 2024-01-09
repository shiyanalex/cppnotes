#include <iostream>

// "Привет :-)))  Как дела? :-(( Отвратительно :-)))( Почему :((("
// "Привет Как дела? Отвратительно Почему"
// :-))))...
// :-(((....
// :-()

void f (std::string& s) {
    std::string s2 = "";
    for (int i = 0; i < s.size();) {
        if (s[i] == ':' && s[i+1] == '-') {
            i+=2;
            if (i < s.size() && s[i+1] == ')') {
                while (i < s.size() && s[i] == ')') {
                    ++i;
                }
            } 
            else if (i < s.size() && s[i+1] == '(')  {
                while (i < s.size() && s[i] == '(') {
                    ++i;
                }
            }
        } else {
            s2.push_back(s[i]);
            ++i;
        }
    }
    std::cout << s2; 
}

int main() {
    std::string s = "Привет :-)))  Как дела? :-(()) Отвратительно :-()( Почему :(((";
    f(s);
}

