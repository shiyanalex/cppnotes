#include <iostream>

class Simple {
public:
    Simple(int a) : a(a) {}
private:
    int a;
};

class SimpleExplicit {
public:
    explicit SimpleExplicit(int a) : a(a) {}
private:
    int a;
};

template <typename S>
void Func(const S& s) {

}

int main() {
    Simple s = 5;
    // SimpleExplicit se = 5; - CE
    SimpleExplicit se = SimpleExplicit(5);

    Func<Simple>(11);
    // Func<SimpleExplicit>(11); - CE
    Func<SimpleExplicit>(SimpleExplicit(11));

}
