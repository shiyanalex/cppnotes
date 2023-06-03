#include <iostream>
#include <vector>

// обращение за границу массива/вектора это НЕ исключение, а UB 
// доступ к элементу вектора через [] не контролируется

// std::exception - базовый тип исключений, у всех них работает what 
// dynamic_cast - std::bad cast
// 		new 	- std::bad_alloc 	(если вся память занята)
// 		.at 	- std::out_of_range (обращение с проверкой границы)
 

int f(int x, int y) {
	if (y == 0)
		throw std::invalid_argument("delenie na 0 ");
	std::cout << x / y; 
	return 0;
}

// function-try block 
void g (int x) try {
    if (x == 1) 
        throw std::runtime_error("BOOM!");
} catch (...) {
    
}

int main() {

	try {
		f(5, 0);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}

	std::vector<int> v(10);
	//v[50] = 1;
	//v.at(50) = 1;

	try {
		v.at(40) = 1;
	} 
	// catch (std::exception& ex) {
	// 	std::cout << ex.what();
	// }
	catch (std::exception const& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        exit(0);
    }

}

// Спецификация (noexcept) - мы говорим что точно из функции ничего не должно вылететь
// warning: 'f' has a non-throwing exception specification but can still throw 

int f(int x, int y) noexcept {
	if (y == 0){
		throw 1;
	} return x/y;
}

int main() {

	f(5,0);
	std::string a;
	std::cout << sizeof(a);

}



