#include <iostream>
#include <vector>

void mymerge(std::vector<int>& v, std::vector<int>& vv, std::vector<int>& m) {
    m.reserve(v.size() + vv.size());
    m = v;
    for (int x : vv) m.push_back(x);
    std::sort(m);
}

int main() {

    std::vector<int> v1{1,2,5,9};
    std::vector<int> v2{3,4,5,6,9};
    
    std::vector<int> dst;
    std::vector<int> dst2;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
    mymerge(v1, v2, dst2);

    for (int x : dst2) std::cout << x;
    std::cout << "\ncorrect one: \n";
    for (int x : dst) std::cout << x;

}

