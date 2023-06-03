#include <iostream>

// The rule of 5
// copy constructor Student s2 = s1;
// copy assignment  s3 = s1;
// destructor
// move constructor Student s5 = std::move(s4);
// move assignment  s6 = std::move(s5);

// RVO / copy ellision
// когда комп видя врем объект и видя что его надо скопировать не копирует и не мувает, а создает его сразу где надо

// move - cast from lvalue to rvalue
// У T уде может быть &, поэтому нужен remove_ref
// TODO why move takes T&&?

// naive move
template<typename T>
move (T& x) noexcept {
    return static_cast<T&&>(x);
}
// std::move
template<typename T>
std::remove_reference_t<T>&& move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}

// std::move_if_noexcept
// если у контруктора своего типа нету noexcept, то вектор будет копировать при перекладывании
template<typename T>
std::conditional_t<std::is_nothrow_move_constructible_v<T>, T&&, const T&>
move_if_noexcept(T& x) noexcept {
    return move(x);
}

// std::remove_reference_t

// std::forward - почему нельзя (T&& x)? шаблонные аргументы
template<typename T>
T&& forward(std::remove_reference_t<T>& x) noexcept {
    return static_cast<T&&> x;
}

template<typename T>
T&& forward(std::remove_reference_t<T>&& x) noexcept {
    static_assert(!std::is_lvalue_reference_v<T>);
    return static_cast<T&&> x;
}

template<typename T>
void swap(T& x, T& y) {
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

int main() {
    
    std::string a = "abcdefg";
    std::string b;
    b = std::move(a);
    //std::cout << b.length() << "\n";
    //std::cout << size(b) << " " << a.size();
    
    int x = 0;
    int&& xx = *x;
}

// lvalue - уже существующий объект (имя переменной всегда lvalue) locator value
// rvalue - создание нового объекта
// xvalue - то что было lvalue но ими перестали быть (например их мувнули)

// xvalue что-то реальное в памяти, но трактуется как rvalue тк мувнули
// prvvalue - просто абстракция используемая компилятором, но не реальный объект в памяти
// temporary materialisation - материализация временного S(S(S(S()))).x;
//
// & - lvalue qualifier только для таких объектов применим 
// Lvalue and Rvalue - не типы объеков, а виды выражений
// Lvalue and Rvalue are categories of expressions, not types! Rvalue reference doesn't mean that it will be rvalue object 
//   T&      T and T&&
// int&& r = std::move(x);

// Reference collapsing (отдав по rvlaue ссылке объект вы сможете ее испортить)
// & &  -> &
// & && -> &
// && & -> &
// && &&-> &&

//universal reference
template<typename T>
void f(T&& x) {
    
}





