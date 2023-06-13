#include <iostream>
#include <cstring>
#include <algorithm>

template<typename T>
void swap(T& x, T& y) {
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

class String {
private: 
	size_t sz = 0;
	char* str = nullptr;

public:
    String() = default;

	String(size_t sz, char c): sz(sz), str(new char[sz]) {
        memset(str, c, sz);
        std::cout << "one\n";
    }

    String(const String& s): sz(s.sz), str(new char[sz]) {
        memcpy(str, s.str, sz);
        std::cout << "two\n";
    }

    String(std::initializer_list<char> lst): sz(lst.size()), str(new char[sz]) {	
      	std::copy(lst.begin(), lst.end(), str);
        std::cout << "three\n";
    }

    String(const char* s): sz(strlen(s)), str(new char[sz]) {
        memcpy(str, s, sz);
        std::cout << "four\n";
    }

    // Move constructor
    // String(String&& s) = default; //WRONG!
    String(String&& s): sz(s.sz), str(s.str) {
        // зануляем потому что у исходного объекта тоже есть деструктор и было бы двойное удаление
        s.str = nullptr;
        s.sz = 0;
    } 

    void sswap(String& s) {
		swap(sz, s.sz);
		swap(str, s.str);
	}

    // Operators
    String& operator=(const String& s) {
		/* delete[] str;
		sz = s.sz;
		str = new char[sz];
		memcpy(str, s.str, sz);
		return *this;  */
        
        String copy = s;
        sswap(copy);
        return *this;
	}
    
    //move assignment
    //String& operator=(String&& s) = default;    
    String& operator=(String&& s) {
        if (this != &s) {
            String new_s = std::move(s);
            sswap(new_s);
        }
        return *this;
    }
	
    String& operator+=(const String& s){
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

    size_t size() {
        return sz;
    }

    const char& operator[](size_t index) const {
        return str[index];
    }

    char& operator[](size_t index) {
        return str[index];
    }

	void print() {
    	for (size_t i = 0; i < sz; ++i) {
            std::cout << str[i];
        }
    }

	~String(){
		delete[] str;
	}
};

int main() {
    String("abc") = "bce";
	String S1 (3, 'X');
    String S2 = S1;                 //copy constructor
	String S3 {'a', 'b', 'c', 'd'}; //initializer_list
    String S4 = "ssd";
    S2.print();
    S1 = S3;                        //copy assignment

    String S5 = std::move(S4);      //move constructor
    std::cout <<"\n===============\n";
    
    String apple = "apple";
    String dest;

    std::cout << "\napple :";
    apple.print();
    std::cout << "\ndest :";    
    dest.print();
    
    dest = std::move(apple);        //move assignment

    std::cout << "\napple :";
    apple.print();
    std::cout << "\ndest :";  
    dest.print();
    //String S5 = (String&&)S4;

}

