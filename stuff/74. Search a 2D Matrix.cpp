#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int l = 0, r = rows * cols - 1;
    
    while (l <= r) {
        int m = (l + r) / 2;
        int midValue = matrix[m / cols][m % cols];
        
        if (midValue == target) return true;
        if (midValue < target) l = m + 1;
        else r = m - 1;
    }
    return false;
}


int main() {
    vector<vector<int>> vec {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    cout << searchMatrix(vec, 3);
}