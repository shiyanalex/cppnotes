#include <iostream>

int main() {
	если не знаешь как привести тип - делай статик каст 

	int x = 10;
	double d = static_cast<double>(x); 

	std::cout << d << std::endl;

	reinterpret_cast - посмотри на байты в памяти как будто это другой тип 

	std::cout<< *reinterpret_cast<double*>(&x); 
	std::cout<< reinterpret_cast<double&>(x);

	const cast - обход защиты константности 

	{
		const int cx = 1;
		// int& x = cx; - error 
		int& x = const_cast<int&>(cx);

		int x = 2;

		std::cout<< x << " " << cx;

	}

}
