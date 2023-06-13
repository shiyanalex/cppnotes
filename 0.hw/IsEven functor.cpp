#include <iostream>
#include <vector>
#include <list> 

struct IsEven {
    bool operator()(int x) const {
        return x%2 == 0;
    }
};

int main() {

	std::list<int> l{1,2,3,4,5,6,7,8,9,10};

    std::vector<int>v;
    std::vector<int>v1;

    std::copy_if (l.begin(), l.end(), back_inserter(v), IsEven());
    
    /*
    std::list<int>::iterator it = l.begin();
    int even;
    while (it != l.end()) {
        if (IsEven()(*it)) {
            v.push_back(*it);
            ++it;
        } else { 
            ++it;
        }
    } */
    
    std::transform(v.begin(), v.end(), std::back_inserter(v1),
               [](int x) {
                          return x / 2;
               }
    );

    for (int x : v1)
        std::cout << x;

    //std::cout << "\n" << v.size();
}
