#include <iostream>
#include <vector>

// # of same element in vector

int lsearch(std::vector<int>& vec, int key) {
    int l = 0;
    int r = vec.size();
    while (l < r) {
        int mid = (l+r)/2;
        if (vec[mid] == key) return key;
        else if (vec[mid] > key) r = mid;
        else l = mid+1;
    }
    return l;
}

int rsearch(std::vector<int>& vec, int x) {
    int l = 0;
    int r = vec.size();
    bool flag = false;
    
    while (l < r && flag == false) {
        int m = (l+r+1)/2;
        if (vec[m] == x) flag = true;
        if (vec[m] < x) l = m;
        else r = m-1;
    }
    return l;
}

void f(std::vector<int>& vec, int x) {
    //std::cout << rsearch(vec, x) << " & ";// << rsearch(vec, x);
    auto upper = std::upper_bound(vec.begin(), vec.end(), x);
    auto lower = std::upper_bound(vec.begin(), vec.end(), x-1);
    std::cout << *upper - *lower + 1<< " " << lsearch(vec, x) << "\n";
}

int main() {

    std::vector<int> v {1,5,3,6,7,3,6,2,9,2,5,7,3};
    std::sort(v.begin(), v.end());
    for (auto& x: v) std::cout << x << " ";
    std::cout << "\n";
    f(v , 61);

}
