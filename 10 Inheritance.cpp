#include <iostream>

// Inheritance / Наследование
// 4.1 Public, Private and Protected Inheritance 

// Public - понятно  
// Private - недоступность в мейне обращаться к объектам Base. + нельзя кастовать к родителю  
// или же Derived сказал что Base его приватная часть
// Protected - доступ только вы, друзья и наследники могут обращаться к полям   

class Base {
public:
	int a = 0;

	void f() {
		std::cout << "Base\n";
	}
	void h() {
		std::cout << "BD\n";
	}

};

class Derived: public Base {
public: 
	//friend int main();
	int b = 1;
	void g() {
		std::cout << "Derived\n";
	}
	//using Base::h;
	void h() {
		std::cout << "HD\n";
	}
};

int main() {

	Derived d;
	d.g();
	d.f();
	std::cout << d.a << "\n";
	d.h();
	d.Base::h();

} 
