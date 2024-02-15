#include <iostream>

// RTTI
// В компайл тайме у виртуальных ф невозможно угадать что будет лежать под ссылкой или указателем
// Поэтому нужная функция должна выбираться в рантайме  
// Вызов виртуальной функции компилятор преобразует в условную инструкцию 
// посмотри что там если написано если одно сделай 1 если другое то 2
// Поэтому компилятор не может отследить приватность функций 
// Base - [[Vptr] [b]] | [vptr]-> base vtable [[typeinfo_ptr][&f]] -> [base_typeinfo()] 
// Derived - [[vptr][d]] | [vptr] -> [[typeinfo_ptr][&f][&g]] -> [base_typeinfo()]

struct Base {
	virtual ~Base() {};	

	virtual void f() {
		std::cout << "APE \n";
	}	

	int b;
	void foo();
};


struct Derived: public Base {
private:						// приват не может спасти от выбора виртуальной версии функции 
	void f() override {
		std::cout << "SEX \n";
	} 
	int d;
	virtual void g() {};

};

int main() {

	int a;
	std::cin >> a;
	Base b;
	Derived d;

	Base& bb = a > 0 ? b : d;
	bb.f();
    std::cout << typeid(b).name();
}


// Dynamic_cast - такой каст, который осуществляется в рантайме (успешность зависит от рантайм состояния)
// применим только к полиморфным типам 

struct Granny {
	virtual void f(){
		std::cout << "1";
	}
};

struct Mother: public Granny {
};

struct Father: public Granny {
};

struct Son: public Mother, public Father {
};


int main() {

	Mother* pm = new Son();

	//Касты мамы типа сына к папе

	static_cast<Father*>(pm);			//Нельзя, статик не может перепрыгивать на другую ветку

	dynamic_cast<Father*>(pm);			//Все гуд

	reinterpret_cast<Father*>(pm); 		//по идее UB тк несовместимые классы

	delete pm;

	Mother m;

	try {
		dynamic_cast<Father&>(m);
	} 
	catch (...){
		std::cout << "ERROR";		// опять по идее должен ловиться
	}


}








