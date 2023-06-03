#include <iostream>

// Virtual destructor problem 
// деструкторы как и функции
// Если деструктор не виртуальный то вызывается только Base и идет утечка памяти
// Тип выражения родитель, но сам объект наследник вызовется правильный деструктор наследника и потом родителя 

struct GrandBase{
	virtual void f() = 0;		//pure virtual
	virtual ~GrandBase() = 0;
};

GrandBase::~GrandBase() {};	//нужно писать если хотим иметь чисто виртуальный деструктор

struct Base: public GrandBase {
	int* a = new int();

	void f() override {}

	virtual ~Base() {
		delete a;
		std::cout << "~Base \n";
	}
};

struct Derived: public Base {
	int* b = new int();

	~Derived() {
		delete b;
		std::cout << "~Derived \n";
	}
};

int main() {

	GrandBase* b = new Derived();
	delete b;

}

