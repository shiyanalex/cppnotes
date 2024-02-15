#include <iostream>

// Multiple Inheritance (Это нам не нужно)

struct mother{
	int m = 1; 
};

struct father {
	int f = 2;
};

struct son: public mother, public father {
	int s = 3;
};

int main() {

	son s;
	std::cout << &s << "\n";
	//std::cout << sizeof(s);	//12 байт, 3 инта по 4

	father* pf = &s;
	mother* mf = &s;
	std::cout << pf << "\n";	//при касте от сына к папе произошло численное изменение указателя 
	std::cout << mf << "\n";
	std::cout << static_cast<son*>(pf);
}

==================================================================
Diamond problem 

struct Granny {
	int g = 0;
	void foo() {}
};

struct mother: public Granny{
	int m = 1; 
};

struct father: public Granny{
	int f = 2;
};

struct son: public mother, public father {
	int s = 3;
};

// [G][M][G][F][S] - обычное наследование 

int main() {

	son s;
	std::cout << sizeof(s) << "\n"; 	//20, оказывается создалось 2 бабушки 

	std::cout << s.g << "\n";			//CE!
	std::cout << s.mother::g << "\n";	//OK
	s.foo(); 							//CE! хоть функция и одна, статик каст тоже CE 
	
}

#include <iostream>

struct Granny {
	int g = 0;
	void foo() {}
};

// virtual - создается только одна копия родителя
struct mother: public virtual Granny{
	int m = 1; 
};

struct father: public virtual Granny{
	int f = 2;
};

struct son: public mother, public father {
	int s = 3;
};

// [G][M][G][F][S] - обычное наследование 
				
// [m_ptr(g)][M][....][f_ptr(G)][F][S][G][...] - выравнивание/ объект лежит в памяти не цельным куском
//     8      4   4       8    	 4  4  4   4

int main() {

	son s;
	std::cout << sizeof(s) << "\n"; // 40 

	std::cout << &s << "\n" << &s.m << "\n" << &s.f << "\n" << &s.s << "\n" << &s.g << "\n";

	std::cout << s.g << "\n";
	std::cout << s.mother::g << "\n";
	s.foo(); 


}




