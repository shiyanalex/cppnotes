#include <iostream>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std::chrono;

int grid_paths(int n, int m) {
    if (n == 1 || m == 1) return 1;
    if (n == 0 || m == 0) return 0;
    return grid_paths(n, m-1) + grid_paths(n-1, m);
}

//c++20
/*
int grid_helper2(int n, int m, std::map<std::pair<int, int>, int>& mapper) {
    std::pair x(n, m);
    if (n == 1 || m == 1) return 1;
    if (n == 0 || m == 0) return 0;
    if (!mapper.contains(x)) mapper[x] = grid_helper2(n, m-1, mapper) + grid_helper2(n-1, m, mapper);
    return mapper[x];
}
*/

//c++14
int grid_helper(int n, int m, std::map<std::pair<int, int>, int>& mapper) {
    auto x = std::make_pair(n, m);
    if (n == 1 || m == 1) return 1;
    if (n == 0 || m == 0) return 0;
    if (mapper.count(x) == 0) mapper[x] = grid_helper(n, m-1, mapper) + grid_helper(n-1, m, mapper);
    return mapper[x];
}

int grid_paths2(int n, int m) {
    std::map<std::pair<int, int>, int> dp;
    return grid_helper(n, m, dp);
    //return grid_helper2(n, m, dp);
}

int main() {

    int n, m;
    std::cin >> n >> m;

    auto start = high_resolution_clock::now();
    std::cout << grid_paths(n, m);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << " time1 : " << duration.count() << "ms" << std::endl;

    auto start2 = high_resolution_clock::now();
    std::cout << grid_paths2(n, m);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    std::cout << " time2 : " << duration2.count() << "ms" << std::endl;
}

