#include <iostream>

class Simple {
public:
    Simple(int a) : a_(a) {}
private:
    int a_;
};

class SimpleExplicit {
public:
    explicit SimpleExplicit(int a) : a_(a) {}
private:
    int a_;
};

class Coordiantes {
private: 
    int longitude;
    int latitude;

public:
    Coordiantes(int x, int y) : longitude(x), latitude(y) {}

    loc_check(Coordiantes&) {
        return std::pair<longitude, latitude>;
    }
}

template <typename S>
void someFunc(const S& s) {

}

int main(int, char**) {
    /*
    Simple s3 = 11;
    // SimpleExplicit se3 = 11; - COMPILE ERROR
    SimpleExplicit se3 = SimpleExplicit(11);

    someFunc<Simple>(11);
    // someFunc<SimpleExplicit>(11); - COMPILE ERROR
    someFunc<SimpleExplicit>(SimpleExplicit(11));

    */

    Coordiantes c (11, 5);
    Coordiantes::loc_check(c);

    return 0;
}
