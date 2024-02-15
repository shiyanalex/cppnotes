#include <iostream>
#include <vector>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, s;
    cin >> n >> t >> s;
    vector<int> speeds(n);
    for (auto& x: speeds) cin >> x;

    int distFirst = speeds[0] * t;
    int lapsFirst = distFirst / s;
    int lastLapDist = distFirst % s;
    int total = 0;

    for (int i = 1; i < n; ++i) {
        if (speeds[i] < speeds[0]) {
            int dist = speeds[i] * t;
            int laps = dist / s;
            int currentLastLapDist = dist % s;
            int takeOvers;

            if (laps == 0) takeOvers = lapsFirst - 1;
            else takeOvers = lapsFirst - laps - 1;

            total += takeOvers;
            if ((lastLapDist == 0 && currentLastLapDist != 0) || lastLapDist > currentLastLapDist) {
                ++total;
            }
        }
    }
    cout << total;
}
