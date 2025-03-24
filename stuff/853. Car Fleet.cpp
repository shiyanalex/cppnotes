#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    unordered_map<int, int> mapper;
    for (int i = 0; i < n; ++i) mapper[position[i]] = speed[i];
    
    sort(position.begin(), position.end());
    stack<double> st;
    
    int ans = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        double time = (double)(target - position[i]) / mapper[position[i]];
        
        if (st.empty() || time > st.top()) {
            st.push(time);
            ++ans;
        }
    }
    return ans;
}

int carFleet2(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars;
    
    for (int i = 0; i < n; ++i) 
        cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
    
    sort(cars.rbegin(), cars.rend());
    
    int fleets = 0;
    double lastTime = 0;
    
    for (auto& car : cars) {
        if (car.second > lastTime) {  // Если машина не догоняет предыдущий флот
            lastTime = car.second;
            ++fleets;
        }
    }
    
    return fleets;
}


int main() {
    int target = 12;
    vector<int> position {10,8,0,5,3};
    vector<int> speed {2,4,1,1,3};
    cout << carFleet(target, position, speed);
}