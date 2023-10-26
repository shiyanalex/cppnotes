#include <iostream>

// начало OOP:
// есть типы и объекты и все программирование сводится к определению своих типов и операциями над ними.
// - переход от обычного прог к ооп происиходит когда появляется возможность создавать свои собственные типы  

// поля - данные в объекте типа (приват)
// методы - операции 

// если нету логики то стуктура, если что то сложное внутри то лучше класс 

class Cereal {	// объявил свой класс, это теперь новый тип 

};

// Инкапсуляция - Объединение данных и функций + ограничение доступа к данным 

// Наследование - новый тип является подтипом

// Полиморфизм (множество форм) это трек группы научно технически реп
// Полиморфизм - от того как мы называем объект зависит какой ответ мы получим 
// 			  объекты разных типов могут совершать одни и теже операции по разному 

struct C {

private:
	int x = 100;
	std::string s;
	double d = 10;

public:
	void add_and_print(int a){
		std::cout << x + a << '\n';
	}

	void add_and_print(double a){
		std::cout << d + a + 5 << '\n';
	}
};

int main (){
	Cereal c; - объявил объект типа 
	std::cout << sizeof(c) << '\n';	// 1 потому что никакой объект не может занимать 0 байт

	C cc;
	cc.add_and_print(1);

}


