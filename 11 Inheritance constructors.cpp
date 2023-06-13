#include <iostream>

struct A {
	A() {std::cout << "A\n"; } 
	~A() {std::cout << "~A\n"; } 

};

struct B {
	B() {std::cout << "B\n";}
	~B() {std::cout << "~B\n";}

};

struct Base {
	int x = 0;
	A a;
	Base() {std::cout << "Base\n";}

	Base(int x): x(x) {std::cout << "Base2 " << x << "\n";}

	~Base() {std::cout << "~Base\n";}

};

struct Derived: public Base {
	int y = 0;
	B b;
	Derived() {std::cout << "Derived\n";}

	Derived(int x, int y): Base(x), y(y) {std::cout << "Derived2 " << x << y << "\n";}

	~Derived() {std::cout << "~Derived\n";}

};

int main() {

	Derived d(1, 2);

}
