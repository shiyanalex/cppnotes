#include <iostream>
#include <vector>

// мета принимает тип и возвращает либо другой тип либо значение

template<typename T>
struct type_identity {
    using type = T;
};

template<typename T>
struct remove_const: type_identity<T> {};

template<typename T>
struct remove_const<const T>: type_identity<T> {};

// Conditional
template<bool B, typename T, typename F>
struct conditional: type_identity<F> {};

template<typename T, typename F>
struct conditional<true, T, F>: type_identity<T> {};

template<bool B, typename T, typename F>
using conditional_t = typename conditional<B, T, F>::type;

template<typename T, T v>
struct integral_constant {
    static const T value = v;
};

template<bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;

using false_type = bool_constant<false>;


template<typename T, typename U>
struct is_same: false_type {};

template<typename T>
struct is_same<T, T>: true_type {};

template<typename T, typename U>
const bool is_same_v = is_same<T, U>::value;

template<typename Head, typename... Tail>
struct conjunction: conjunction<Head, conjunction<Tail...>> {};

template<typename T, typename U>
struct conjunction<T, U>: conditional_t<T::value, U, false_type> {};

template<typename... Ts>
struct short_conjunction: bool_constant<(Ts::value && ...)> {}; //fold expression

// SFINAE idiom and std::enable_if
//
// SFINAE - Substitution Failure Is Not An Error.

template<bool B, typename T>
struct enable_if {};

template<typename T>
struct enable_if<true, T>: type_identity<T> {};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;


/*
template<typename T>
auto f(const T& v) -> typename T::value_type {
    return v[0];
}
*/

/*
template<typename T, typename U = typename T::value_type>
int f(const T& v) {
    return v[0];
}
*/

// хочется написать template<typename T, typename = enable_if_t<std::is_class_v<T>>> и !enable_if_t, но это редефинишен

template<typename T, enable_if_t<std::is_class_v<T>, bool> = true>
int f(const T& v) {
    return v[0];
}

template<typename T, enable_if_t<!std::is_class_v<T>, bool> = true>
int f(const T& x) {
    return x;
}

// SFINAE based type traits

template<typename T, typename U = int(T::*)>
true_type is_class_helper(int);

template<typename T>
false_type is_class_helper(...);

template<typename T>
struct is_class: decltype(is_class_helper<T>(0)) {};

int main() {
    std::vector vec = {1,2,3,4,5};
    std::cout << f(vec) << "\n";
    int x = 3;
    std::cout << f(x) << "\n";

    // в компайл тайме проверка условия
    static_assert(!is_class<int>::value);
    static_assert(is_class<std::vector<int>>::value);

}
