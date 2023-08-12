#include <iostream>
#include <vector>
#include <set>
#include <map>


// препроцессинг (//, include, define) -> компиляция -> ассемблирование -> линковка (все файлы и библиотеки в один exe)
// единица трансляции - cpp file
// в хедере меняем что-то и все файлы где он включен будут пересобираться 

// Найти реальный пример использования протектед наследования
// Оптимизирует ли компилятор постфиксный инкремент у итераторов или он делает копию

// Class template argument deduction (CTAD) - можно не указывать инт в векторе
// #define - макросы
// enum - набор именнованных констант (эконом, комфорт, бизнес)
// noexcept - no exeptions
// constexpr - compile time if
// decltype - compile time type
// explicit - все конструкторы от одного аргумента (широта долгота)
// final - restrict inheritance
// extern - some fuction from another file
// mutable - позволяет изменять локальные данные в лямбде / даже если объект константный поле изменяемо (кэширование)

int main() {

    std::vector<int> v {2,5,4,8,5,7,1,3,9,15};

}
