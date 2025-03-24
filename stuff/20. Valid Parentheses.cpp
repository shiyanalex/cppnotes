#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    for (auto x : s) {
        if (x == '(' || x == '{' || x == '[') {
            st.push(x);
        } 
        else {
            if (st.empty()) return false; // Make sure stack isn't empty before accessing top
            
            if ((x == ')' && st.top() == '(') ||
                (x == '}' && st.top() == '{') ||
                (x == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched bracket
                }
        }
    }
    
    return st.empty();
}

int main() {
    string  s = "({[)";
    cout << isValid(s);
}