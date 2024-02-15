#include <iostream> 

int main(){

	signed / unsigned (without +/-)

	int - usually 4 bytes 
	long / short / long long (8 bytes)


	вещественные типы:
	float - 4 bytes 
	double - usually 8 bytes 
 	long double -  16 bytes


	char - 1 symbol in ASCII, 1 byte in memory from -128 to 127, or from 0 to 255
	char b='b';
	b = 32; // 32 in ASCII = space 
	std::string a = "one more time";

	std::cout<<a<<std::endl;
	std::cout<<a[1]<<std::endl;
	std::cout<<a.length()<<std::endl; //a.size()
	std::cout<<"g"+a<<std::endl;
	std::cout<<a+"g"<<std::endl;
	a+='g';
	std::cout<<a<<std::endl;


	bool - 1 byte true/false 


	char to int 
	char c = 'a'
	itn b=a;


	bool to int 2+true=3  
	int to bool if (5){ } all numbers exept 0 true 

	void - type without value, function doesnt return a value

	const int x = 5; //cant change it 

	==================================================================

	if(condition) {

	}	else {

	}

	switch(expression) {

	case 1:
		statements...;
		break;

	case 2:
		statements...;
		break;

	default:

	}


	for(declaration; bool-expression; expression) {
		statements
	}

	while() {

	}


	do {

	} while (condition)

	==================================================================

	Arithmetic operators:
	+ - * / % (reminder)

	Bitwise operators: 
	& (and)
	|(or)
	^ (xor)
	~ (not)
	<< (Shift bits left/right) 

	Logical operators: 
	&& - AND 
	|| - OR 
	! - NOT 

	Ternary operator: 
	condition ? a : b; true / false 
















}