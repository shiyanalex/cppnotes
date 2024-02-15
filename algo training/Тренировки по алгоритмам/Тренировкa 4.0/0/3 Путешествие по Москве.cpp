#include <iostream>
#include <vector>
#include <math.h>
#define PI 3.14159265
#define int double
using namespace std;
int ax, ay, bx, by;

int arc_len(int r, int angle) {
    //return PI * r * (angle / 180);
    return r * angle;
}

int find_angle() {
    //int r1 = atan2(ay, ax);
    //int r2 = atan2(by, bx);
    //int radian = abs(r1 - r2);
    int radian = atan2(ax * by - ay * bx, ax * bx + ay * by);

    //int angle = radian * (180 / PI);
    //if (angle < 0.0) angle += 360.0;
    return abs(radian);
}

int run() {
    int r1 = sqrt(ax*ax + ay*ay);
    int r2 = sqrt(bx*bx + by*by);
    int angle = find_angle();
    int arc = arc_len(min(r1, r2), angle);
    return min(r1+r2, arc+abs(r1-r2));
}

int32_t main() {
    cin >> ax >> ay >> bx >> by;
    cout << fixed << run();
}
