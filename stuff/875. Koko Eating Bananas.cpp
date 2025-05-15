#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    
    while (l < r) {
        int m = l + (r - l) / 2;
        
        int hours = 0;
        for (int x : piles) {
            hours += (x + m - 1) / m;
        }
        
        if (hours <= h) r = m;
        else l = m + 1;
    }
    return l;
}


int main() {
    vector<int> piles = {30,11,23,4,20};
    cout << minEatingSpeed(piles, 5);
}