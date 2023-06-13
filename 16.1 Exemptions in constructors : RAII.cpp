#include <iostream>

// RAII ака умный указатель
// Resource acquisition is initialization - захват ресурса есть инициализация 
// каждый раз когда хочу захватить ресурс, создаю объект отвечающий за владение этим ресурсом
// тогда каждый раз когда выхожу из области видимости объекта, он и захваченные ресурсы будут освобождаться  
// Потому что мы могли захватить какой то участок памяти, потом нас выкинуло, он не очистился и теперь мы его не можем использовать
template <typename T>
class SmartPtr {        // Smart - следит и сам освобождает память unique_ptr / shared_ptr / weak_ptr
private: 
	T* prt;
public: 
	SmartPtr(T* prt): prt(prt) {}
	~SmartPtr(){
		delete prt;
	}	
};


struct S {
	//int *p = nullptr;
	SmartPtr<int> p = nullptr;

	S(): p(new int (5)){
		throw 1;
	}
	
	~S() {
		//delete p;
	}
};

void f() {
	int *p = new int(5);
	throw 1;
	// Указатель просто забудется и будет утечка памяти
	delete p;
}

int main() {

	try {
		f();
	} catch (...) {

	}

	try {
		S s;
	} catch (...) {

	}

}

