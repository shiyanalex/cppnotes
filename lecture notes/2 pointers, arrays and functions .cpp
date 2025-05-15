#include <iostream>

//	Память бывает Cтатическая (Static), Автоматическая (Stack) и Динамическая (Heap - Куча)
//
//	Статическая - инфа которая хранится на протяжении всей жизни программы (Глобальные преременные, неймспес) 				Поскольку она ограничена, то может переполниться и будет stack overflow
//
//	Автоматическая - Работает как стек, Локальные переменные заполняются и потом снимаются
//
//	Динамическая - выделяется вручную в runtime (new, malloc) и освобождается вручную. Используем надстройки типа вектора и shared_ptr


int main() {

	void f(){
		int a;
		std::cout<< &a <<'\n';
		static int x = 0;
		std::cout << x << '\n';
		x++;
		f();
	}

	int x = 5;
	int* p = &x; 					// int* - Pointer & - get address
	std::cout << x << std::endl;
	std::cout << &x << std::endl;
	std::cout << p << std::endl;
	std::cout << &p << std::endl;
	std::cout << *p << std::endl;	// Dereferencing - Разименование 
	

====================================

	int a[] = {1,2,3,4,5};			// массив на стеке поэтому нельзя созать a[100000]
	std::cout << a[1] << std::endl;
	std::cout << 3[a] << std::endl; // 3[a] = *(3+a)

	int* p = a;
	std::cout << p[2] << std::endl;	// массив и указатель практически одно и тоже

	int* pa = new int[100];			// new int создает динамический массив, это отдельная память которой больше 
									// + в дин массиве можно использовать переменную как его размер 
	delete[] pa;

	int n = 10;
	int a[n];
	std::cout << a[2] << '\n';	// -1823299744 trash 

	int b[10];
	std::cout << b[2];			// 0 ok ????

====================================
	
	function overload
	тип возвращаемого значения - тип возвращаемого функцией значения 
	(или void если значение не возвращается)

	0.0 по умолчанию double, если нужно float то 0.0f

	void f(int){ 
		std::cout << 1;
	}

	void f(double){ 
		std::cout << 2;
	}

	void f(int a, int b=0){		//функция с арг по умолчанию  

	}

	int main() {
		f(0.0);
		f(1);			// 21 
	} 
		
} 

====================================
	Вывод функции

	int f(){
		cout << 1;
		return 2;
	}

	int g(){
		cout << 3;
		return 4;
	}


	int main() {
		f();						//1

		cout << f() << endl;		//12

		g();						//3

		cout << g() << endl;		//34

		cout << f() + g() << endl;	//136

		int c = f() + g();			//13

		cout << f() * g() << endl;	//138

	}

====================================
	Еще примеры функции
		
	return type f (parameter1) параметр - это принятый функцией аргумент, 
	значение, переданное из вызывающего кода

	double f(double){
	    std::cout << 1;
	    return 0;

	}

	int f(int){
	    std::cout << 2;
	    return 0;
	}

	// void f(int){ 
	//     std::cout<<1;
	// }

	// void f(double){ 
	//     std::cout<<3;
	// }


	void g(int, char){
	    std::cout<<"hello"<<'\n' ;
	}

	bool cmp(int a, int b){
	    return a > b;
	}

	int main() {

	    f(1.3);           // 31 
	    f(1);         
	    std::cout<<'\n';

	    void (*pg)(int, char) = g;
	    pg(1, 66);
	    //pg(1, 'a');

	    std::cout<<'\n';
	    int a[5] = {2,4,1,9,0};
	    std::sort(a, a+5, cmp);

	    for(int i = 0; i < 5; i++){
	        std::cout<<a[i]<<' ';
	    }


	} 
=====================================================================

	std::string a;
	std::cin >> a;
	std::cout << a.length() << std::endl;

	// while(a[k] != '\n') {	//нажали enter, цикл запускается последний раз,
	// 	k++;					//но стринг уже закрылся, поэтому сегфолт 
	// }		
	
	int k = 0;
	while(a[++k]);
	std::cout << k;

	std::string message;
	getline (std::cin, message);
	std::cout << message;

	push_back добавляет копию объекта (или обеспечивает перемещение, если возможно)
	emplace_back создает объект непосредственно в конце вектора, без лишнего копирования (или перемещения).

	std::string str;
	std::getline(std::cin, str);
	std::vector<char> word(str.begin(), str.end());

	for (char x: str){
		std::cout << x << ' ';
	}
