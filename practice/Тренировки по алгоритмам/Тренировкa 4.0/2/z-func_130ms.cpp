#include <iostream>
#include <vector>

std::vector<int> zfunc(std::string& s) {
	int n = s.size();
    std::vector<int> z(n);

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
    std::ios_base::sync_with_stdio(false);
    std::string v;
    std::cin >> v;
    for (auto x: zfunc(v)) std::cout << x << " ";
}
