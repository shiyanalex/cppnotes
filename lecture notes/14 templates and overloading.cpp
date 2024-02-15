#include <iostream>
#include <vector>

// Templates

template <typename T>
const T& max(const T& a, const T& b){
	return a > b ? a : b;
}

template <typename T>
const T pi = 3.14;

template <typename T>
struct vector {
	template <typename U>
	void push_back(const U&);
};

template <typename T>
template <typename U>
void vector<T>::push_back(const U& x) {
	//...
}

int main() {

	std::cout << max(1,2) << "\n";
	std::cout << pi<double>;

}

// Template overloading

template <typename T, typename U>
	void f(T x, U y){
		std::cout << 1;
	}

// since c++20
auto f(auto x, auto y) {
    std::cout << "smth";
}

template <typename T>
	void f(T x, T y){
		std::cout << 2;
	}

void f(int x, double y) {
	std::cout << 3;
}

int main() {
	f(1, 1.2);		//3
	f(1, 2);		//2
	f(1.2, 3);		//1
 
}



