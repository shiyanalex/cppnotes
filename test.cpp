#include <iostream>
#include <vector>

// препроцессинг (//, include, define) -> компиляция -> ассемблирование -> линковка (все файлы и библиотеки в один exe)
// единица трансляции - cpp file
// в хедере меняем что-то и все файлы где он включен будут пересобираться 


//Class template argument deduction (CTAD) - можно не указывать инт в векторе

/* 
RAII idiom is с very simple, it means that any resource allocation (acquisition) is done in object constructor and
deallocation respectively in destructor, in other words resource acquisition must succeed for initialization to succeed.
This method guarantees that sources are held only while object is alive. Therefore, there are no object or resource
leaks.
*/

// не используем сишный поинтер
// нужный пример протектед наследования
// #define - макросы
// enum - набор именнованных констант (эконом, комфорт, бизнес)
// noexcept - no exeptions
// constexpr - compile time if
// decltype - compile time type
// explicit - все конструкторы от одного аргумента (широта долгота)
// final - no inheritance
// extern - some fuction from another file
// union - 
// mutable - в лямбде можно локальные данные изменять 

struct A {
    int x = 0;
    A() {};

    A(const A&) { std::cout << "A copy\n"; }

    A(A&&) { std::cout << "A move\n"; }
};

int main() {

    std::vector v {1,5,3,2,4,6,0,8,9,3};
    A a;
    int mid = 5;
    /*
    std::sort(v.begin(), v.end(), [=, a = std::move(a)] (int x, int y) mutable {
        return std::abs(x - mid) < std::abs(y - mid);
    }); */
    

    auto f = [=] (int x, int y) {
        return std::abs(x - mid) < std::abs(y - mid);
        std::ignore = a;
    };
    
    std::sort(v.begin(), v.end(), f);
    

    for (int x : v) std::cout << x;

}

