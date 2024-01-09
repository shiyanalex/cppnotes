#include <iostream>
#include <chrono>
#include <fstream>
#include <set>

void f1() {
    std::fstream file("input.txt");

    if (file.is_open()) {
        std::cout << "File is open : \n";

        int x;
        std::set<int> st;
        while (file >> x) {
            st.insert(x);
        }
        std::cout << st.size();
    } else {
        std::cout << "Error GG \n";
    }
}

void f2() {
    std::fstream file("input.txt");

    if (file.is_open()) {
        std::cout << "File is open : \n";

        int x;
        std::bitset<10000000> visited;
        while (file >> x) {
            visited[x] = true;
        }
        std::cout << visited.count();
    } else {
        std::cout << "Error GG \n";
    }
}

int main() {

    auto begin = std::chrono::high_resolution_clock::now();
    f1();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\n" <<std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << "ms" << std::endl;
    auto begin2 = std::chrono::high_resolution_clock::now();
    f2();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "\n" <<std::chrono::duration_cast<std::chrono::milliseconds>(end2-begin2).count() << "ms" << std::endl;
}
