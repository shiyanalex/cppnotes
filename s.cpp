#include <iostream>

struct Time {
private:
    int h = 0;
    int m = 0;
    int s = 0;    
public: 

    Time(int x) {
        while (x > 59) {
            if (x > 3600) {
                ++h;
                x -= 3600;
            } if (x > 60) {
                ++m;
                x -= 60;
            }
            s = x;
        }
    }
    
    void gtime() {
        std::cout << h << ":" << m << ":" << s;
    }

};

int main() {
    
    Time t(3848);
    
    t.gtime();
}
