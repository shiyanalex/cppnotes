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


class Car {
private:
    double longitude;
    double latitude;

    enum CarClass {
        econom = 1, bussines, elite
    };

public:

    Car(double x, double y, CarClass carclass);
    
    void moving () {
        longitude++;
        latitude++;
    }
        
    std::pair<double, double> loc_check() {
        return std::pair<double, double> (longitude, latitude);
    }

    std::string ClassCheck(CarClass one) {
        std::string className[] = { "econom", "bussines", "elite"};
        return className[one];
    }
};

template <typename S>
void someFunc(const S& s) {

}

int main() {
    /*
    Simple s3 = 11;
    // SimpleExplicit se3 = 11; - COMPILE ERROR
    SimpleExplicit se3 = SimpleExplicit(11);

    someFunc<Simple>(11);
    // someFunc<SimpleExplicit>(11); - COMPILE ERROR
    someFunc<SimpleExplicit>(SimpleExplicit(11));

    */

    Car mycar (11.2342, 5.2341, Car::CarClass::econom);
    mycar.loc_check();

    return 0;
}
