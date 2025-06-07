#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// k-хороший если в нём не более k различных чисел
// Вывести l,r - номер самого левого и самого правого элементов k-хорошего подотрезка наибольшей длины.

void longestGoodSubarray(const vector<int>& v, int k) {
    unordered_map<int, int> mapper;
    
    int len = 0;
    int a = 0, b = 0;
    
    for (int l = 0, r = 0; r < v.size(); ++r) {
        mapper[v[r]]++;
        
        while (mapper.size() > k) {
            --mapper[v[l]];
            if (mapper[v[l]] == 0) mapper.erase(v[l]);
            ++l;
        }
        
        if (r - l > len) {
            len = r - l;
            a = l + 1;
            b = r + 1;
        }
    }
    cout << len << "\n" << a << " " << b;
}

int main() {
    vector<int> vec{6,5,1,2,3,2,1,4,5};
    longestGoodSubarray(vec, 3);
}