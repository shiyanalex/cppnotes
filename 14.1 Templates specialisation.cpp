#include <iostream>

// Specialisation
template <typename T>
struct S {
	void f(){
		std::cout << "1 \n";
	}
};

// Full specialisation
template <>
struct S<int> {
	void f(){
		std::cout << "2 \n";
	}
};

// Partial specialisation	* & [] const, const&  
template <typename T>
struct S<T*> {
	void f(){
		std::cout << "3 \n";
	}
};

int main() {
	S<bool> s;
	s.f();

	S<int> ss;
	ss.f();

	S<int*> sss;
	sss.f();

}


