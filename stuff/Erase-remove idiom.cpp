#include <iostream> 
#include <vector>

struct IsEven {
    bool operator()(int x) const {
        return x%2 == 0;
    }
};

int main () {

    std::vector<int> v;    

    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);
    }
    
    auto begin = std::chrono::high_resolution_clock::now();

    // O(n^2) 130ms 
    //
    for (;;) {                // equivalent to while(true) aka infinite loop
    auto it = std::find_if(v.begin(), v.end(), IsEven());
    if (it == v.end()) break;
        v.erase(it);
    }

    // O(n) 1ms
    v.erase(remove(v.begin(), v.end(), 2), v.end());
    
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << "ms" << std::endl;

}
