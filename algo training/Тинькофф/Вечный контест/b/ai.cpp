#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<pair<int, int>> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    int maxFriends = 0;
    int currentTime = 0;
    int currentPos = 0;

    for (int i = 0; i < n; i++) {
        int dist = abs(friends[i].first - currentPos);
        if (currentTime + dist + friends[i].second <= T) {
            currentTime += dist + friends[i].second;
            currentPos = friends[i].first;
            maxFriends++;
        }
    }

    cout << maxFriends << endl;

    return 0;
}
