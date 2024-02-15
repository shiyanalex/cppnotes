#include <iostream>
#include <vector>

int main() {
    
    std::vector v{1,2,4,2,6,2,74,25};

    for (std::size_t i = 0; auto& d : v) {
        std::cout << i++ << ' ' << d << '\n';
    }
}
