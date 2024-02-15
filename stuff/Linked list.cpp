#include <iostream>
// Связный список — это динамическая структура данных, состоящая из узлов, 
// которые содержат в себе в классическом варианте два значения: 
// первое — это какое-либо данное  
// второе — это указатель на следующий узел в списке 
// В отличие от массива будь то статического, либо динамического, динамический список можно увеличивать во время работы программы. 

// Back insert

struct Node {
	int data;
	Node* next;
};

class list {
	Node* head;

public: 
	list() {
		head = NULL;
	};

	void addNode (int d) {
		Node* nd = new Node();
		nd->data = d;
		nd->next = NULL;

		if (head == NULL)
			head = nd;
		else {
            Node* current = head;

            while(current->next != NULL)
                current = current->next;
            current->next = nd;
        }
	};

	void printlist() {
		Node *current = head;

		while (current != NULL){
			std::cout << current->data << ' ';
			current = current->next;
		} 
	};
};


int main() {

	list mylist;
	mylist.addNode(5);
	mylist.addNode(10);
	mylist.addNode(15);
	mylist.printlist();

}

// Front insert // stack // first in last out 

// struct Node {
// 	int data;
// 	Node* next;
// };

// class list {
// 	Node* head;

// public: 
// 	list() {
// 		head = NULL;
// 	};

// 	void addNode (int d) {
// 		Node* nd = new Node();
// 		nd->data = d;
// 		nd->next = head;
// 		head = nd;
// 	};

// 	void printlist() {
// 		Node *current = head;

// 		while (current != NULL){
// 			std::cout << current->data << ' ';
// 			current = current->next;
// 		} 
// 	};

// };

// int main() {

// 	list mylist;
// 	mylist.addNode(5);
// 	mylist.addNode(10);
// 	mylist.addNode(15);
// 	mylist.printlist();

// }



