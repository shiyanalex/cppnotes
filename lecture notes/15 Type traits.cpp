#include <iostream>

// Type traits - характеристики типов
// c++11 в type_traits написано много таких полезных функций как ниже
// это все метафункции (функции от типов) : 
template <typename T, typename U>
struct is_same {
	static const bool value = false;

};

template <typename T>
struct is_same<T, T> {
	static const bool value = true;
};

template<typename T>
struct remove_reference {
    using type = T;
};

template<typename T>
struct remove_reference<T&> {
    using type = T;
};

template<typename T>
struct remove_const {
    using type = T;
};

template<typename T>
struct remove_const<const T> {
    using type = T;
};

template<typename T>
struct remove_extent {
    using type = T;
};

template<typename T>
struct remove_extent<T[]> {
    using type = T;
};

// since c++14 
template<typename T>
using remove_const_t = typename remove_const<T>::type;

//since c++17 
template<typename U, typename V>
const bool is_same_v = is_same<U, V>::value;


template <typename T, typename U>
void f(T x, U y) {
	
	//...
	typename remove_const<U>::type a;
    //...

	if (is_same_v<T, U>) {

	} else {

	}

}

template<typename T>
struct C {
    C() = delete;
};

int main() {

    const char cc = 'c';
    remove_const<decltype(cc)>::type a;
    a = 'a';
    std::cout << a << cc;

    // decay - снимает все * и &
    // C<typename std::decay<int*[5][5]>::type> x;

}
