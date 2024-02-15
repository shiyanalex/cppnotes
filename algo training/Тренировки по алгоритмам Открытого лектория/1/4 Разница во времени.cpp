#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// D. Разница во времени

int f(std::vector<int>& mi) {

    std::sort(mi.begin(), mi.end());

    int mini = INT_MAX;

    for (int i = 0; i < mi.size() - 1; i++){
        int diff = mi[i+1] - mi[i];

        if (diff < mini) mini = diff;
    }

    int last = (mi[0] + 1440) - mi[mi.size() - 1];
    mini = std::min(mini, last);
    
    return mini;
}


int main() {

    int num;
    std::cin >> num;

    int h, m = 0;

    std::vector<int> t;

    for (int i = 0; i < num; ++i) {
        std::string time;
        std::cin >> time;

        if (sscanf(time.c_str(), "%d:%d", &h, &m) >= 2) {
            int min = h*60 + m;
            t.push_back(min);
        }
    }

    std::cout << f(t);
} 

