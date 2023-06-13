#include <iostream>

// Polymorphism / Полиморфизм 
// от того как мы называем объект зависит какой ответ мы получим 
// объекты разных типов могут совершать одни и теже операции по разному 

// Virtual function / Виртуальная функция 
// 1) Если к наследнику обратиться через ссылку на родителя, вызовется функция наследника 
// 2) Версия функции выбирается в рантайме, а не в момент компиляции
// т.е сначала ищется функция в Base, в рантайме смотрится переопределена ли она 

// Они позволяют создавать общий код, который может работать как с объектами базового класса, 
// так и с объектами любого его класса-наследника. При этом базовый класс определяет 
// способ работы с объектами, и любые его наследники могут предоставлять конкретную реализацию этого способа.

// Полиморфный тип - если определен хотя бы 1 виртуальный метод 
// override - явное переопределение, чтобы компилятор ругался почаще 
// с помощью виртуальных функций можно реализовать динамический полиморфизм

struct Base {
	virtual void f() {
		std::cout << 1 << "\n";
	}
};

struct Derived: public Base {
	void f() override {
		std::cout << 2 << "\n";
	}

	// void f() const {		// будет выводить 1 потому что конгруэнтность разная 
	// 	std::cout << 2;
	// }
};
struct Subderived: public Base {
	void f() const final {      // final - override и запрещаем всем ниже оверрайдить
		std::cout << 3 << "\n";
	}
}
int main() {

	Base b;
	b.f();
	Derived d;
	d.f();

	std::cout << "\n";

	Base b1 = d;
	b1.f();			//1 это просто копия 

	Base& b2 = d;
	b2.f();			//1 или 2 если virtual 

	Base* b3 = new Derived();
	b3->f();

}

struct S {
    int x;
    double y;
    void f (char c) {};
}

int main() {
    
    int S::*p = S::x;
    S s(5, 1.2);

    void (S::* pf)(char) = &S::f;
    (s.*pf)('a');

    S* ps = s;
    (ps->*pf)('b');

    std::cout << sizeof(p) << "\n"; // 8 обычный указатель (сдвиг относительно начала структуры)
    std::cout << s.*p << "\n";
    
}

// Abstract and pure virtual classes 
// Abstract class - базовый класс, который не предполагает создания экземпляров. Shape
// Pure virtual - чисто виртуальный метод, т.е нельзя создать Shape и вызвать Area (можно)
// Если в классе хоть один виртуальный метод, то класс виртуальный
// Чисто виртальные методы можно определять, но делать этого не нужно 


#include <iostream>

class Shape {
public: 
	virtual double area() const = 0;

};

double Shape::area() const {
	return 0.5;
}

struct Square: public Shape {
	double area() const override {
		return 1;
	}
};

int main() {
	//Shape s;
	Square s;
	std::cout << s.area() << "\n";
	std::cout << s.Shape::area() << "\n";

	Shape& ss = s;
	// Shape* ss = &s;
	std::cout << ss.area() << "\n";

}

