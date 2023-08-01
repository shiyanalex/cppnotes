#include <iostream>
#include <set>

// WA test 10

int main() {

    int n, k;
    std::cin >> n >> k;

    std::set<long> st;
    
    // использую if for тк нету for else лупа, а мне нужно проверить краевой случай

    int i = 0;
    if (i != n) {
        while (i < n) {

            long x;
            std::cin >> x;
            auto pos = st.find(x);

            if (pos != st.end()) { // если нашли то ищем расстояние между тем где нашли и концом

                auto end = st.end();
                if (distance(pos, end) <= k) {
                    std::cout << "YES";
                    break;
                }
                else {
                    std::cout << "NO";
                    break;
                }
            }

            st.insert(x);
            ++i;
        }
    } if (i == n) {
        std::cout << "NO";
    }

    //for (auto& it : st) std::cout << it << "\n";
}
