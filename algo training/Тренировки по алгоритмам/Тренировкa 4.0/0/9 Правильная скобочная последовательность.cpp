#include <iostream>
#include <stack>
using namespace std;

bool check(string& s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (!st.empty()) {
            if ((s[i] == ')' && st.top() == '(') ||
                (s[i] == '}' && st.top() == '{') || 
                (s[i] == ']' && st.top() == '[')) st.pop();
            else st.push(s[i]);
        } else st.push(s[i]);
    }
    if (st.empty()) return true;
    else return false;
}
int main() {
    string s;
    cin >> s;
    check(s) ? cout << "yes" : cout << "no";
    return 0;
}
