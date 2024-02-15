#include <iostream>
#include <vector>
#include <map>

int main() {

    int N;
    long ideal;
    long long time;

    std::cin >> N >> ideal >> time;

    std::vector<long> weights;

    for (int i = 0; i < N; ++i) {
        long x;
        std::cin >> x;
        weights.push_back(x);
    }

    std::map<int, long> mapper;

    for (int i = 0; i < N; i++) {
        mapper[i + 1] = abs(weights[i] - ideal);
    }

    std::vector<std::pair<int, long>> sorted_mapper;

    for (auto it = mapper.begin(); it != mapper.end(); ++it) {
        sorted_mapper.push_back(std::make_pair(it->first, it->second));
    }

    std::sort(sorted_mapper.begin(), sorted_mapper.end(), [](std::pair<int, long> a, std::pair<int, long> b) {
        return a.second < b.second;
    }); 

    std::vector<int> ids;

    for (auto it = sorted_mapper.begin(); it != sorted_mapper.end(); ++it) {
        time = time - it->second;

        if (time >= 0) {
            ids.push_back(it->first);
        }
        else break; 
    }
    std::cout << ids.size() << "\n";
    for (auto x : ids) std::cout << x << " ";
}
