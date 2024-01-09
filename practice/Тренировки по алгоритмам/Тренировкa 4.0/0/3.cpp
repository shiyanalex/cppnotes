#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int ax, ay, bx, by;

double run() {
    double r1 = sqrt(ax*ax + ay*ay);
    double r2 = sqrt(bx*bx + by*by);
    if (r1 == r2) {
        float angle = atan2(ay - by, ax - bx) * 180 / M_PI;
        std::cout << angle << "\n";
        int ans = angle / 360 * (2 * M_PI * r1);
        return ans;
    }
    else {
        return 10;
    }
}

int main() {
    cin >> ax >> ay >> bx >> by;
    std::cout << run();
}
