#include <iostream>

using std::cout;
using std::endl;

struct Node {
    int data = -1;
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;

    Node(int data) : data(data) {
        // пусто
    }
};

class Tree {
public:
    Tree(Node* root) : root(root) {
        // пусто
    }

    const Node* search(Node* new_node) {
        Node* current_root = root;
        while (current_root != NULL && current_root->data != new_node->data) {
            if (new_node->data < current_root->data) {
                current_root = current_root->left;
            } else {
                current_root = current_root->right;
            }
        }
        return current_root;
    }

private:
    Node* root;
};

Tree getTreeExample() {
    // объявляем набор узлов
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node5 = new Node(5);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    // устанавливаем связи между узлами
    node2->parent = node3;
    node3->parent = node7;
    node3->left = node2;
    node3->right = node5;
    node5->parent = node3;
    node7->left = node3;
    node7->right = node8;
    node8->parent = node7;

    return Tree(node7);
}

int main() {
    Tree tree = getTreeExample();

    cout << (tree.search(new Node(2)) != NULL) << endl;
    cout << (tree.search(new Node(4)) != NULL) << endl;
}