#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> zfunc(std::string& s) {
	int n = s.size();
    std::vector<int> z(n, 0);

    int l = 0;
    int r = 0;
	for (int i = 1; i < n; ++i) {
		if (i <= r)
            z[i] = std::min(r-i+1, z[i-l]);
		
        while (i + z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];

		if (i + z[i]-1 > r)
            l = i, 
            r = i+z[i]-1;
	}
    return z;
}

int main() {
    std::ifstream file("input.txt");
    std::string s;
    while (!file.eof()) {
        std::string tmp;
        getline(file, tmp);
        s += tmp;
    }
    auto z = zfunc(s);
    //std::string ans;
    for (int i = 0; i <= s.size(); ++i) {
        if (z[i]+i >= s.size()) {
            std::cout << i;
            //ans = s.substr(0, i-1);
            break;
        }
    }
    //std::cout << ans;
} 
