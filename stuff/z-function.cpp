#include <iostream>
#include <vector>
std::vector<int> v;

// O(n^2)
void zfunc(std::vector<int>& v) {
    std::vector<int> sol(v.size(), 0);

    for (int i = 1; i < v.size(); ++i) {
        int k = 0;        
        int j = i;
        while (v[k] == v[j]) {
            ++sol[i];
            ++k;
            ++j;
        }
    }
    for (auto x : sol) std::cout << x << " ";
}

// O(n^2)
int good(int i) {
    int l = 0;
    int r = v.size() - i;

    while (l < r) {
        int m = (l+r)/2+1;
        bool flag = true;
        for (int j = 0, k = i; j < m; ++j, ++k) {
            if (v[j] != v[k]) flag = false;
        }
        if (!flag) r = m-1;
        else l = m;
    }
    return l;
}

void zfunc2(std::vector<int>& v) {
    std::vector<int> sol(v.size(), 0);

    for (int i = 1; i < v.size(); ++i) {
        if (v[0] != v[i]);
        else sol[i] = good(i);
    }
    for (auto x : sol) std::cout << x << " ";
}

// O(n)
void zfunc3(std::vector<int>& s) {
	int n = (int) s.size();
    std::vector<int> z(n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = std::min(r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
    for (auto x : z) std::cout << x << " ";
}

int main() {
    v = {1,2,1,3,1,2,1,4,1,2,1,3,1,2,1};
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";
    ztrivial(v);
    std::cout << "\n";
    zfunc(v);
    std::cout << "\n";
    zfunc2(v);
    std::cout << "\n";
    zfunc3(v);
} 
