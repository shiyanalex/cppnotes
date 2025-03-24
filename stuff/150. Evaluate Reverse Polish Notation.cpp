#include <iostream>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    
    for (auto x : tokens) {
        if (x == "+") {
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            int ans = first + second;
            st.push(ans);
        } else if (x == "/") {
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            int ans = first / second;
            st.push(ans);
        } else if (x == "-") {
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            int ans = first - second; 
            st.push(ans);
        } else if (x == "*") {
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            int ans = first * second; 
            st.push(ans);
        } else {
            int num = stoi(x);
            st.push(num);
        }
    }
    return st.top();
}

int main() {
    vector<string> vec{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(vec);
}