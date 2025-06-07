#include <iostream>
#include <stack>
using namespace std;

int run(const string& s) {
    stack<int> st;

    for (int i = 0; i < s.size(); ++i) {

        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-') {
            int sign = 1;
            if (s[i] == '-') sign *= -1;
            st.push((s[i+1] - '0') * sign);
            ++i;
        }
        else if (s[i] == '*' || s[i] == '/') {
            char op = s[i];
            ++i;
            int right = s[i] - '0';
            int left = st.top(); st.pop();
            if (op == '*') st.push(left * right);
            else st.push(left / right);
        }
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string s1 = "-2+2*3+4";      // 8
    string s2 = "3+4*3/6+4-3*2"; // 3
    cout << run(s1) << "\n" << run(s2) << endl;
}
