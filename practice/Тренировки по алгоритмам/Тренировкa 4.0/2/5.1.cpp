#include <iostream>
#include <vector>

std::vector<int> hash(std::string& s) {
    std::vector<int> h(s.size());

    for (int i = 0; i < s.size(); ++i) {
        h[i] = s[i]-'`';
    }
    for (int i = 1; i < s.size(); ++i) {
        h[i] = h[i-1]*10+h[i];
    }
    return h;
}

bool ok() {
    for (int i = 0; i < x; ++i) {
        
    }
}

int pal(std::vector<int>& v) {
    int ans = v.size();

    for (int i = 2; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if () ++ans;
        }
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    for (auto x: hash(s)) std::cout << x << " ";
}
