#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// Function call overloading. Comparators / перегрузка ()
// для своего типа можно перегрузить не только [], но и ()
// нужно для создания компараторов / функторов предикатов 
// MyType x;
// x(5);

// Функциональный класс 
struct GreaterThanThree {			// объекты этой структуры будут функциями от одной переменной
	bool operator()(int x){			// такие объекты называются функциональными / функторами 
		return x > 3;
	}
};

struct MyCompare {
	bool operator()(int x, int y) const noexcept {
		return abs(x) < abs(y);
	}
};

int main(){

	std::vector<int> v{1,2,3,7,9,3,4,8,12,0,5};

	//find поиск элемента, равного value -- почему он выдает 3??? 
	//Returns an iterator to the first element in the range [first, last) that satisfies specific criteria
	//std::cout << *std::find(v.begin(), v.end(), 9) << std::endl;

	//find_if ищет не по значению, а по условию 
	std::cout << *std::find_if(v.begin(), v.end(), GreaterThanThree()) << "\n";	

	//find_if_not обратное от find_if 
	std::cout << *std::find_if_not(v.begin(), v.end(), GreaterThanThree()) << "\n";

	//существует ли эл в векторе
	if (std::find(v.begin(), v.end(), 4) != v.end())
		std::cout << "this element exists\n";
	else 
		std::cout<< "there is no such element\n";

	//std::set<int> s; 	//упорядоченное множество 

	std::sort(v.begin(), v.end(), MyCompare());

	for (int x: v){
		std::cout << x << ' ';
	}
	std::cout << "\n";

	// литеральный суффикс 
	// 5_uid - константа userid / userid(5)

}
