#include <iostream>

template <bool B, typename T, typename F>
struct my_conditional {
	using type = F;
};

template <typename T, typename F>
struct my_conditional<true, T, F> {
	using type = T;
};

template <bool B, typename T, typename F>
using my_conditional_t = typename my_conditional<B, T, F>::type;


template <typename T> 
void f(T) {
	std::cout << "Now type is " << typeid(T).name();
}

int main() {

	// первый если тру, второй если фолс 
	my_conditional_t<true, int, double> Type1;
	my_conditional_t<false, int, char> Type2;

	std::cout << typeid(Type1).name() << "\n";
	std::cout << typeid(Type2).name() << "\n";

	const bool run = false; 

	my_conditional_t<run, int, double> X;
	f(X);


}