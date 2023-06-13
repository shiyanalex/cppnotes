#include <iostream>
#include <cstring>
#include <algorithm>

// shallow copy - поверхностное копирование по умолчанию - поэлементное копирование
// Битовая маска - данные, которые используются для выбора отдельных битов 10111011 & 00001000 = 00001000

// Глубокое копирование выделяет память для копии, а затем копирует фактическое значение, 
// поэтому копия живет в отдельной памяти от источника. 
// Таким образом, копия и источник различаются и никоим образом не влияют друг на друга.

class String {
private: 
	size_t sz = 0;
	char* str = nullptr;	//указатель на массив с символами

	//если в полях есть ссылка, она не станет константной от того если объект константен 
	friend void f(int); 	//друзья могут юзать приват вне класса 

public: 
	//конструктор позволет создать объект класса от параметров, (у него нет возвращаемого значения)
	//String() {} // пустой конструктор (дефолтный) 
	String() = default; // компилятор сам создает конструктор по умолчанию 

	//запрет на создание от инта 
	String(int) = delete; 

	//size_t - unsigned int / long long или беззнаковое число  
	//конструктор создания из n эллементов 

	//списки инициализации в конструкторе :
	//!!инициализация идет в порядке объявления (приват) 
	String(size_t sz, char c): sz(sz), str(new char[sz]) {
		// this->sz = sz;
		// str = new char[sz];
		memset(str, c, sz);
		// for(int i = 0; i < sz; i++){
		// 	str[i] = c;
		// }
		//std::cout << "a";
	}

	//конструктор копирования (компилятор может сам создать его, но в нашем случае это не работает)
	String(const String& s): sz(s.sz), str(new char[sz]) {
		// sz = s.sz;
		// str = new char[sz];
		memcpy(str, s.str, sz);
		//std::copy()
		//std::cout << "b";
	}	

	//делегирующий конструктор копирования
	// String(const String& s): String(s.sz, '\0') {
	// 	memcpy(str, s.str, sz);
	// 	std::cout << "c";
	// }

	//У initializer_list приоритет выше чем у других конструкторов 
	//String S1{3, 'X'}; но всегда можно написать в круглых скобках
	String(std::initializer_list<char> lst): sz(lst.size()), str(new char[sz]) {	
		// sz = lst.size();
		// str = new char[sz];
		std::copy(lst.begin(), lst.end(), str);	//откуда до куда и что получили
		std::cout << "initializer_list ";
	}

	//конструктор от набора чаров
	String(const char* s): sz(strlen(s)), str(new char[sz]) {
		// sz = strlen(s);
		// str = new char[sz];
		memcpy(str, s, sz);
		// for(int i = 0; i < sz; i++){
		// 	str[i] = s[i];
		// }
	}

	//оператор присваивания
	// String& operator=(const String& s){
	// 	delete[] str;
	// 	sz = s.sz;
	// 	str = new char[sz];
	// 	memcpy(str, s.str, sz);
	// 	return *this;
	// }

	//оператор присваивания copy-and-swap
	// String& operator=(const String& s){
	// 	String copy = s;
	// 	swap(copy);
	// 	return *this;
	// }

	//оператор +=
	String& operator+=(const String& s){	//его можно как то улучшить, но я не знаю как :(
		size_t ns = sz + s.sz;
		char* temp = str;
		str = new char[ns];
 
		int k = 0;
		for (size_t i = 0; i < sz; i++) {
			str[k++] = temp[i];
		}

		for (size_t j = 0; j < s.sz; j++) {
			str[k++] = s.str[j];
		}

		delete[] temp;
		return *this;
	}

	void swap(String& s) {
		std::swap(sz, s.sz);
		std::swap(str, s.str);
	}
    size_t size() {
        return sz;
    }

    const char& operator[](size_t index) const {
        return str[index];
    }
    char& operator[](size_t index) {
        return str[index];
    }
	void show() { 
    	std::cout << str << std::endl;
    }  
    
    // деструктор / освобождение памяти от ненужных переменных 
	~String(){
		delete[] str; // в деструкторе нужно писать только нетривиальные действия
	}

};

	void f(int) {				//ура мы друзья!!!
		String s("abrakadabra");
		s.sz = 0;
	};

	//Операторы ввода из потока
	// std::ostream& operator<<(std::ostream& out, const String& s){
	// 	for (int i = 0; i < s.size; i++){
	// 		out << s[i];
	// 	}
	// 	return out;
	// }

	// std::istream& operator>>(std::stream& in, const String& s){	//оператор ввода из потока уместно сделать другом 

	// }

	// String::~String(){
	// 	delete[] str;
	// }

int main(){
	// если создан хоть один конструктор, то нужно его объявлять иначе UB 
	// если все поля публичные то можно инициализировать с помошью { }
	{
		// String S1(3, 'X');	// конструктор создания
		// String S2 = S1;		// конструктор копирования 
		// S2.show();			

		// String S3{'a', 'b', 'c'}; //initializer_list 
		// String S1{3, 'X'};

		//String S3;				// конструктор по умолчанию 
		//std::cout << sizeof(S3) << std::endl;;	// выделяет 16 байт 
		//S3.len(); //- segmentation fault 

		//S2 = S1 оператор присваивания != копированию 
		//если дефолтный, то будет segmentation fault, потому что в первый раз никто delete не вызвал, 
		//а потом 2 раза delete по одному месту  

		String S4("ape");
		S4.show();
		String S5("sex");
		S4 += S5;
		S4.show();
		S4.len();
		S4 = S5;
		S4.show();
		S4.len();

	}
	// включается деструктор?

}

