#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>


// not finished cuz exams
void func(std::vector<int>& vec) {
    int min = 1440;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        for (auto it1 = vec.begin(); it1 != vec.end(); ++it1) {
            int x = *it1 - *it;
            if (x < min){
                min = x;
            }
        }
    }
    std::cout << min;
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

    for (int x : t) { std::cout << x << " "; }
    
    
} 

