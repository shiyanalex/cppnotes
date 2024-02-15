#include <iostream>

// Variadic templates / шаблон с переменным количеством аргументов 
// Treated head separately and applied to all other arguments

void print() {} // отдельная перегрузка для 0 аргументов 

template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail) {
	std::cout << head << "\n";
    //std::cout << sizeof...(tail) << "\n"; // кол-во эл в хвосте
	print(tail...);                       // распарсили пакет на отдельные аргументы
    //if constexpr (sizeof...(tail) > 0) print(tail...);
}

// analog is_same is_homogeneous - однородный true if all types are the same

template<typename First, typename Second, typename... Types>
struct is_homogeneous {
    static const bool value = std::is_same_v<First, Second> && is_homogeneous<Second, Types...>::value;
};

template<typename First, typename Second>
struct is_homogeneous<First, Second> {
    static const bool value = std::is_same_v<First, Second>;
};

// Alias (not working)
template<typename... Args>
const bool is_homogeneous_v = is_homogeneous<Args...>::value;

// Template deduction rule
// при шаблонной подстановке отбрасывается & и const 

int main() {

	print(1, 4, "sex", 5.5, "dildo");   // формально 6 разных функций принт
    std::cout << is_homogeneous_v<int, int, int, int> << "\n";
    std::cout << is_homogeneous_v<int, char, double, int> << "\n";


}

