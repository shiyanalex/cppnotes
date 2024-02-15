#include <iostream>
#include <vector>
using namespace std;
// https://contest.yandex.ru/contest/57974

char map[8][8];
int res = 0;

void check(int x, int y) {
    bool top, left, right, bottom = false;
    
    auto valid = [](int x, int y){
        return (0 <= x && x < 8 && 0 <= y && y < 8 && map[x][y] == '.');
    };

    if (map[x][y] == '.') {
        top = valid(x, y+1);
        bottom = valid(x, y-1);
        left = valid(x-1, y);
        right = valid(x+1, y);
    }
    if (top && left && bottom) ++res;
    if (top && right && bottom) ++res;
    if (left && right && bottom) ++res;
    if (left && right && top) ++res;
}

int main() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> map[i][j];
        }
    }
    /*
    cout << "  ";
    for (int i = 0; i < 8; ++i) cout << i;
    cout << "\n";
    for (int i = 0; i < 8; ++i) { //y
        cout << i << " ";
        for (int j = 0; j < 8; ++j) { //x
            cout << map[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    */

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            check(i, j);
        }
    }
    cout << res;
}

