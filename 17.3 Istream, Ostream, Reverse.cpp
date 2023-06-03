#include <iostream>
#include <vector>
#include <list>

// std::ifstream in("input.txt")
// std::istringstream iss(s); - строка как стрим 

// Istream Iterator

template <typename T>
class istream_iterator {
	std::istream& in;
	T value;			// последний считаный объект 
public: 
	istream_iterator(std::istream& in) : in(in) {
		in >> value;
	}

	istream_iterator<T>& operator++ () {
		in >> value;
		return *this;
	}							

	T& operator* () {
		return value;
	}
};

// Ostream Iterator итератор передает данные на вывод  например принять инфу по итератору из шаблона
// и использовать ее где то в функции которая запрашивает итератор 

template <typename T>
class ostream_iterator {
	std::ostream& out;
public: 
	ostream_iterator(std::ostream& out) : out(out) {}
	//ostream_iterator(std::ostream& out, const char c) : out(out), const c (c){} // дописать конструктор с сепаратором

	ostream_iterator<T>& operator++() {
		return *this;
	}							

	ostream_iterator<T>& operator=(const T& value) {
        out << value;
		return *this;
	}							

	ostream_iterator<T>& operator*() {
		return *this;
	}
};

// Reverse-iterator 

template <typename Iterator>
struct reverse_iterator {
private: 
	Iterator iter;
public: 
	reverse_iterator (const Iterator& iter) : iter(iter){}

	reverse_iterator<Iterator>& operator ++ () {
		--iter; 
		return *this;
	}

	Iterator base() const {
		return iter;
	}
};

int main() {

    // istream
	std::vector<int> v;
	istream_iterator<int> it(std::cin);

	for (int i = 0; i < 3; ++i,	++it) {
		v.push_back(*it);
	}

	//for (int x : v)
	//	std::cout << x;

    // ostream
    ostream_iterator<char> itr(std::cout);
    *itr = 'H'; // без * тоже работает
    ++itr;
    *itr = 'I';
    
    ostream_iterator<int> ot(std::cout, ",");
    std::copy(v.begin(), v.end(), ot);
    for (int x : v) ot = x;
 	
	//Reverse 
	//std::list<int> v{1,2,3,4,5,6,7,8,9,10};
	// for (auto it = v.rbegin(); it != v.rend(); ++it){
	// 	std::cout << *it << " ";
	// }

	// Или можно не ебать мозги и написать
	// for (auto it = std::prev(v.end(),1); it != v.begin(); --it){
	// 	std::cout << *it << " ";
	// }

	// С вектором определен минус, поэтому можно просто:
	// for (auto it = v.end() - 1; it != v.begin(); --it){
	// 	std::cout << *it << " ";
	// }

}

