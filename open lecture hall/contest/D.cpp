#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(3, vector<int>(N));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    map<int, vector<int>> d1;
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < 3; j++) {
            temp.push_back(a[j][i]);
        }
        d1[i+1] = temp;
    }

    int Q;
    cin >> Q;
    vector<vector<int>> a2(3, vector<int>(Q));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < Q; j++) {
            cin >> a2[i][j];
        }
    }

    map<int, vector<int>> d2;
    for (int i = 0; i < Q; i++) {
        vector<int> temp;
        for (int j = 0; j < 3; j++) {
            temp.push_back(a2[j][i]);
        }
        d2[i+1] = temp;
    }

    vector<int> arr;
    for (auto it = d2.begin(); it != d2.end(); it++) {
        vector<int> aa;
        for (auto jt = d1.begin(); jt != d1.end(); jt++) {
            if (it->second[0] == 0 && it->second[1] == 0 && it->second[2] == 0) {
                if (jt->second[0] == 0 && jt->second[1] == 0 && (jt->second[2] == 0 || jt->second[2] == 1)) {
                    aa.push_back(jt->first);
                    break;
                }
            }
            if (((it->second[0] >= jt->second[0]) && (it->second[1] - jt->second[1] >= 0)) || ((it->second[2] == jt->first) && (jt->second[2] == 1))) {
                aa.push_back(jt->first);
                break;
            }
        }
        if (aa.size() == 0) {
            arr.push_back(0);
        } else {
            arr.push_back(aa[0]);
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

