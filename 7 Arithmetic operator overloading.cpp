#include <iostream> 

struct Complex {
	double re = 0.0;
	double im = 0.0;

	Complex(double x = 0.0, double y = 0.0): re(x), im(y) {}

	Complex& operator+=(const Complex& z) {
		re += z.re;
		im += z.im;
		return *this;
	}	

	//префикс возвращает значение
	Complex& operator++(){
		*this += 1;
		return *this;		
	}

	//постфикс возвращает копию (линейное время) 
	Complex operator++(int){
		Complex copy = *this;
		++*this;
		return copy;
	}

};

	//Return Value Optimization (создает объект сразу где предполагается использовать)
	//оператор + занимает линейное время 
	//выносим за скобки чтобы 1 + с работало 
	Complex operator+(const Complex& a, const Complex& b) {
		Complex copy = a;
		return copy += b;
	}

	bool operator<(const Complex& a, const Complex& b){
		return a.re * a.re + a.im * a.im < b.re * b.re + b.im * b.im; 
	}

	bool operator>(const Complex& a, const Complex& b){
		return b < a;
	}

	bool operator==(const Complex& a, const Complex& b){
		return !(a < b || b < a);
	}


int main() {
	Complex c(1.2);
	Complex d(1.0, 5.5);
	//copy elision
	//Complex sum = c + d;
	1.0 + c;
	c + 1.0;

	//std::cout << c.print();
	//std::cout<< sizeof(c) << '\n';	// 1 потому что никакой объект не может занимать 0 байт

}