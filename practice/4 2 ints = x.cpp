#include <iostream>
#include <vector>

void f (std::vector<int>& vec) {

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        for (auto it1 = vec.begin(); it1 != vec.end(); ++it1) {
            if (*it + *it1 == 15){
                std::cout <<"(" << *it << "," << *it1 << ")";
                return;
            }
        }
    
    }
}

template <typename T>
int max(T data) {
    int max = 0;
    for (auto& x: data) {
        if (x >max) {
            max = x;
        }
    }
    return max;
}


int main() {
    std::vector<int> v{1,2,3,4,5,6,7,10,15,22,12};
    f(v);
    std::cout << max(v);
}

