#include <iostream>
using namespace std;

int main() {

    int n = 20;

    int a = 0;
    int b = 1;
    int s = 0;
    
    while (a <= n) {
        s += a;
        int temp = b;
        b += a;
        a = temp;
    }
    std::cout << s;
}
