#include <iostream>
#include <vector>

// препроцессинг (//, include, define) -> компиляция -> ассемблирование -> линковка (все файлы и библиотеки в один exe)
// единица трансляции - cpp file
// в хедере меняем что-то и все файлы где он включен будут пересобираться 

// Найти реальный пример использования протектед наследования
// Оптимизирует ли компилятор постфиксный инкремент у итераторов или он делает копию

// Class template argument deduction (CTAD) - можно не указывать инт в векторе
// Dont use C-style pointer
// #define - макросы
// enum - набор именнованных констант (эконом, комфорт, бизнес)
// noexcept - no exeptions
// constexpr - compile time if
// decltype - compile time type
// explicit - все конструкторы от одного аргумента (широта долгота)
// final - restrict inheritance
// extern - some fuction from another file
// mutable - позволяет изменять локальные данные в лямбде / даже если объект константный поле изменяемо (кэширование)

struct A {
    int x = 0;
    A() {};

    A(const A&) { std::cout << "A copy\n"; }

    A(A&&) { std::cout << "A move\n"; }
};

int main() {

    std::vector v{1,5,3,2,4,6,0,8,9,3};
    A a;
    int mid = 5;

    /*
    std::sort(v.begin(), v.end(), [=, a = std::move(a)] (int x, int y) mutable {
        return std::abs(x - mid) < std::abs(y - mid);
        std::ignore = a;
    }); 
    */

    auto f = [=, a = std::move(a)] (int x, int y) {
        return std::abs(x - mid) < std::abs(y - mid);
        std::ignore = a;
    };
    std::sort(v.begin(), v.end(), f);

    for (int x : v) std::cout << x;

}

