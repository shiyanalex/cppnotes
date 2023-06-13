#include <iostream> 
#include <vector>
#include <algorithm>

void record(std::vector<long long>& vec, int x) {
    long long t = 0;
    for (int i = 0; i < x; ++i) {
        std::cin >> t;
        vec[i] = t;
    }
}

int main() {

    int nplat = 0;
    int nvol = 0;    
    std::cin >> nplat >> nvol;

    std::vector<long long> platforms (nplat);
    std::vector<long long> volunteers (nvol);
    record(platforms, nplat);
    record(volunteers, nvol);
    platforms.push_back(0);

    std::vector<long long> spaces(0);
    auto it1 = platforms.rbegin();
    auto it2 = platforms.rbegin() + 1;

    while (it2 != platforms.rend()) {
        if (*it2 > *it1) {
            long long t = *it2 - *it1;
            spaces.push_back(t);
            it1 = it2;
            ++it2;
        } else ++it2;
    }

    std::sort(spaces.begin(), spaces.end(), std::greater<long long>());
    std::sort(volunteers.begin(), volunteers.end(), std::greater<long long>());
    
    int result = 0;
    auto vl = volunteers.begin();
    auto sp = spaces.begin();
    while (vl!= volunteers.end()) {
        if(sp == spaces.end()) break;
        if (*vl > *sp) ++vl;
        else {
            ++vl;
            ++sp;
            ++result;
        }
    } 
    std::cout << result;

}
