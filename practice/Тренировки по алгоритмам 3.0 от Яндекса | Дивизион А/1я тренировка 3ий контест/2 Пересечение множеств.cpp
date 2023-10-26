#include <iostream>
#include <sstream>
#include <vector>
#include <set>

int main() {

    std::string s;
    getline(std::cin, s);
    std::set<int> nums;

    std::istringstream is(s);
    int in;

    while(is >> in) {
        nums.insert(in);
    }

    s = "";
    getline(std::cin, s);
    std::istringstream is2(s);
    std::vector<int> ans;

    while(is2 >> in) {
        if (nums.contains(in)) ans.push_back(in);
    }

    std::sort(ans.begin(), ans.end());
    for (auto& x: ans) std::cout << x << " ";

}
