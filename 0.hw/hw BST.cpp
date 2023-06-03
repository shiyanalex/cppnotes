#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class BST {

struct node {
	int data;
	int key;
	node* left;
	node* right;
};

node* root;

node* Empty(node* t) {
	if(t == NULL)
		return NULL;
	{
	Empty(t->left);
	Empty(t->right);
	delete t;
	}
	return NULL;
}

node* NewNode(int key, int data) {
	node* t = new node;
	t->key = key;
	t->left = NULL;
	t->right = NULL;
	t->data = data;
	return t;
}

int MaxDepth(node*t) {
	if (t == NULL)
	return 0;
	return max(MaxDepth(t->left),MaxDepth(t->right))+1;
}

void PrintNode(node* t) {
	cout <<"[ "<< t << ' ' << t->key << ' ' << t->data << ' ' << t->left << ' ' << t->right <<" ] ";
}

node* AddInLeaf(int k,int d, node* t) {
	if(t == NULL) {
		t = new node;
		t->key = k;
		t->data = d;
		t->left = t->right = NULL;
	}

	else if(k < t->key)
	t->left = AddInLeaf(k,d, t->left);

	else if(k > t->key)
	t->right = AddInLeaf(k,d, t->right);
	return t;
}

void TurnLeft(node* &pA) {
	node* pB = pA->right;
	node* pBL = pB->left;
	pB->left = pA;
	pA->right = pBL;
	pA = pB;
}

void TurnRight(node* &pA) {
	node* pB = pA->left;
	node* pBR = pB->right;
	pB->right = pA;
	pA->left = pBR;
	pA = pB;
}

void BSTClear(node*t) {
	if ( t ) {
		if ( t->left ) BSTClear( t->left );
		if ( t->right ) BSTClear( t->right );
		t = NULL;
	}

}

node* findMin(node* t) {
	if(t == NULL)
	return NULL;

	else if(t->left == NULL)
	return t;

	else
	return findMin(t->left);
}

node* findMax(node* t) {
	if(t == NULL)
	return NULL;

	else if(t->right == NULL)
	return t;

	else
	return findMax(t->right);
}

node* remove(int x, node* t) {
	node* temp;
	if(t == NULL)
	return NULL;

	else if(x < t->key)
	t->left = remove(x, t->left);
	else if(x > t->key)
	t->right = remove(x, t->right);
	else if(t->left && t->right) {
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	else {
		temp = t;
		if(t->left == NULL)
		t = t->right;

		else if(t->right == NULL)
		t = t->left;
		delete temp;
	}

	return t;
}

void PrintLNR(node* t) {
	if(t == NULL)
	return;
	PrintLNR(t->left);
	PrintNode(t);
	PrintLNR(t->right);
}

node* find(node* t, int x) {
	if(t == NULL)
	return NULL;

	else if(x < t->data)
	return find(t->left, x);
	else if(x > t->data)
	return find(t->right, x);
	else
	return t;
}

public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = Empty(root);
	}

	void AddInLeaf(int k, int d) {
		root = AddInLeaf(k,d, root);
	}

	void remove(int x) {
		root = remove(x, root);
	}

	void display() {
		PrintLNR(root);
		cout << endl;
	}

	void search(int x) {
		root = find(root, x);
	}

	void BSTClear () {
		root = NULL;
	}

	int GetMaxDepth() {
		return MaxDepth(root);
	}

};

int main() {
	BST t;
	t.AddInLeaf(20,100);
	t.AddInLeaf(25,122);
	t.AddInLeaf(15,144);
	t.AddInLeaf(10,192);
	t.AddInLeaf(30,112);
	t.display();
	t.remove(20);
	t.display();
	t.remove(25);
	t.display();
	t.remove(30);
	t.display();
	t.BSTClear();
	cout <<"Depth of tree = "<< t.GetMaxDepth()<<endl;
	system("pause");
	return 0;
}