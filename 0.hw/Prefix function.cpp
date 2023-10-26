#include <iostream>
#include <vector>

// prefix function 
// 0,0,1,0,3,0,1,0,7,0,1,0,3,0,1

void prefix(std::vector<int>& v) {
    std::vector<int> sol = v;
    std::fill(sol.begin(), sol.end(), 0);

    for (int i = 1; i < v.size(); ++i) {
        int same = 0;
        int k = 0;        
        int j = i;
        if (v[k] != v[j]) sol[i] = same;
        
        while (v[k] == v[j]) {
            ++same;
            ++k;
            ++j;
        }
        sol[i] = same;

    }

    for (auto x : sol) std::cout << x << ",";
    std::cout << "\n";    
    for (auto x : v) std::cout << x << ",";
}

void prefix1(std::vector<int>& v) { 

    std::vector<int> sol(v.size(), 0);

    for (auto it = v.begin() + 1; it != v.end(); ++it) {
        int same = 0;
        auto it1 = it;
        auto it2 = v.begin();
        if (*it1 != *it2) sol.push_back(same);
        
        else { 
            while(*it1 == *it2 && it1 != v.end()) {
                ++same;
                ++it1;
                ++it2;
            }
            sol.push_back(same);
        }
        
    }
    
    for (auto x : sol) std::cout << x << ",";
    std::cout << "\n";    
    for (auto x : v) std::cout << x << ",";
}


int main() {
    
    std::vector<int> vec{1,2,1,3,1,2,1,4,1,2,1,3,1,2,1};
    prefix(vec);

} 
