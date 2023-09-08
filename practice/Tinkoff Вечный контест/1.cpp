#include <iostream>

int main() {

    int a,b,c,d;
    std::cin >> a >> b >> c >> d;

    d > b ? std::cout << a + (d-b)*c : std::cout << a;

}
