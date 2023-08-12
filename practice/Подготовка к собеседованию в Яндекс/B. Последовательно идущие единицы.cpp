#include <iostream>
#include <vector>

void maxLenght(std::vector<int> vec) {

    int max = 0;

    for (int i = 0; i < vec.size(); ++i) {
        int tmp = 0;

        while (vec[i] == 1) {
            ++tmp;
            ++i;
        }

        if (tmp > max) max = tmp;
        tmp = 0;
    }
    std::cout << max << "\n";
}

int main() {

    int n;
    std::cin >> n;

    /*
    std::vector<int> vec;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }
    maxLenght(vec); 
    */

    int max = 0;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 1) {
            ++max;
        }
        else { 
            if (max > result) {
            result = max;
            }
            max = 0;
        }
    }
    std::cout << (max > result ? max : result) << std::endl;

}

