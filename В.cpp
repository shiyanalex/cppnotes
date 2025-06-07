#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
#define int ll

const int INF = 1e17;

int n, l, s;

int getDistance(int start, int end) {
    if (end >= start) return end - start;
    return l - start + end;
}

map<int, pair<int, int>> taxis; // id -> {timestamp, position}

set<int> candidates;

void findCandidates(int currentTime, int requestDistance, int requestPos) {
    candidates.clear();

    for (const auto& [id, info] : taxis) {
        int taxiTime = info.first;
        int taxiPos = info.second;

        int timeDiff = currentTime - taxiTime;
        int taxiNextPos = (taxiPos + s * timeDiff) % l;

        int dist1 = getDistance(taxiPos, requestPos);
        int dist2 = getDistance(taxiNextPos, requestPos);

        int maxDist = max(dist1, dist2);

        if (maxDist <= requestDistance * s) {
            candidates.insert(id);
        }

        if ((int)candidates.size() == 5) break;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> s;

    for (int i = 0; i < n; ++i) {
        string type;
        cin >> type;

        if (type == "TAXI") {
            int timestamp, id, pos;
            cin >> timestamp >> id >> pos;
            taxis[id] = {timestamp, pos};
        } else {
            int timestamp, id, pos, request;
            cin >> timestamp >> id >> pos >> request;

            findCandidates(timestamp, request, pos);

            if (candidates.empty()) {
                cout << "-1\n";
            } else {
                for (int id : candidates) {
                    cout << id << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
