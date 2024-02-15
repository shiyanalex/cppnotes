#include <iostream>

struct A{
	static int x;	// сатическое поле - которое общее на весь класс
					// для обращения даже не нужен объект класса	
    // пример статического поля - сколько существует объетов данного класса  
	// все статическое создается на запуске программы и существует до конца работы программы 
};

struct S{
    int x;
    double d;
    void f(char c) {}
};

//поле mutable позволяет изменить значение у константного объекта (запрос find оптимизирует дерево) 

int A::x = 0;

int main() {
    int S::* p = &S::x; //Указатель на поле d (объект не нужен)
    S s{3, 2.12};
    std::cout << s.*p << "\n";

	A one;
	A two;
	one.x = 5;
	std::cout << one.x << two.x << A::x;

}

// Singleton - в любой момент времени существует только один объект класса (подключение к бд)

struct Singleton {
private:
    Singleton () {};
    Singleton (const Singleton&) = delete;

public:

    static Singleton* ptr;

    static Singleton& getInstance() {
        if (!ptr) ptr = new Singleton();
        return *ptr;
    }
};

Singleton* Singleton::ptr = nullptr;

int main() {
    Singleton& s = Singleton::getInstance();
}

// Оператор приведения типа
struct UserID {
    int id = 0;

    explicit UserID(int id): id(id) {}

    operator int() const {
        return id;
    }
};

    uid + 5;
    5 + uid;

// explicit - запрещает неявное вызов оператора Применяется к конструктору / оператору привдения типов. 
// explicit широта / explicit долгота и 
// String s; s + 'a'; если нет конструктора строки от чара, а преобразуется в 97 и получится строка + 97 нулей
// Пиши explicit когда конструктор от одного аргумента 
// big integer int bool помечаем explicit и  

class C {
	static C* obj;	// можно инициализировать статическое поле внутри класса только 
	C() {}			// если это константа ЦЕЛОЧИСЛЕННОГО типа  
public: 
	static C& GetObj(){
		if (obj) return *obj;
		obj = new C();
		return *obj;
	}	
	static void destroy(){
		delete obj;
	}
};

C* C::obj = nullptr;

//int main() {
//
//    C c = C::GetObj();
//
//}





