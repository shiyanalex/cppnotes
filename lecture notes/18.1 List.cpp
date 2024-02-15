#include <iostream>

template<typename T, typename Allocator = std::allocator<T>>
class List {
struct BaseNode {
    BaseNode* prev;
    BaseNode* next;

    struct Node: BaseNode {
        T value;
    };
    //BaseNode* fakeNode{NULL, NULL};
    BaseNode* fakeNode = reinterpret_cast<BaseNode*>(new int8_t(sizeof(Node)));
    //typename Alloc::rebind<Node<T>>::other alloc;
};
public: 
    //написать конструкторы
    List() {}
    
    struct Iterator {
        BaseNode* node;
        
        //правильно сделать константность, реверс 
        Iterator& operator++() {
            node = node->next;
            return *this;
        }
        Iterator& operator--() {
            node = node->prev;
            return *this;
        }
        T& operator*() {
            return node->value;
        }
        
    };
};


int main() {


}
