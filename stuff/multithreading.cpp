#include <iostream>
#include <thread>

using std::string;
using std::thread;


void task1(string a) {
	std::cout << "task1 " << a << "\n";
}

void task2(string a) {
	std::cout << "task2 " << a << "\n";
}

void task3(string a) {
	std::cout << "task3 " << a << "\n";
}



int main() {

	thread t1(task1, "Hello");
	thread t2(task2, "World");
	thread t3(task3, "third");


	t1.join();
	t2.join();
	t3.join();

	//непонятно что будет работать быстрее

}