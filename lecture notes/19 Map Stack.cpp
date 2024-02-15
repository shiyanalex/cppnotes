#include <iostream>
#include <deque>

// Stack, queue, priority queue - адаптеры над контейнерами по умолчанию от дека, но можно явно попросить сделать над вектором 
// map - красное-черное дерево, хранит ключ значение 

// Vecor - iterators, pointers and references invalidation 
// Deque there is Iterator invalidation, but safe with pointers and references
// List - no invalidation
// Map (red black tree) / set - no invalidation
// Unordered map (hash table using chaining) - iterator invalidation, but safe with pointers and references

template<typename T, typename Container = std::deque<T>>
class Stack {
private:  
    Container container;
public: 
    void push(const T& value) {
        container.push_back(value);
    }
    void pop() {
        container.pop_back();
    }
    T& top(){
        return container.back();
    }
};


// in map adressing using [] creates value by default
// in c++ on compiler level key is constant type
template<typename First, typename Second>
struct pair {
    First first;
    Second second;
};

template<typename T>
struct less {
    bool operator(const T& x, const T& y) const {
        return x < y;
    }
};

// Копаратор тоже может кидать искл, но это нам не мешает, тк при вращении к-ч дерева он не используется 
// Он используется только когда мы ищем место куда вставить и если вылетает искл, то дерево мы еще не поменяли
template<typename Key, typename Value>
    typename Compare = std::less<Key>
class map {
    using value_type = pair<const Key, Value>;
private: 
    BaseNode* leftmost;
    BaseNode* root;
    Compare comp;

    struct BaseNode {
        BaseNode* left;
        BaseNode* right;
        BaseNode* parent;
    };

    struct Node: BaseNode() {
        value_type kv;
        bool red;
    }   

public:                 //полный обход всего дерева занимает линейое время O(n), но просто инкремент может работать за логарифм 
    struct iterator {   //increment of iterator might take O(logn)
        BaseNode* node;
        
        value_type& operator*() const{
            return (static_cast<Node*>(node))->kv;
        }
    };

    Value& operator[](const Key& key) {};   //создает вершину по умолчанию, поэтому нельзя в конст мапе
    Value& at(const Key& key) {};
    const Value& at(const Key& key) const {};

    iterator find(const Key& key);

    size_t count(const Key& key) const;
};


int main() {

    std::map<std::string, int> m;

    std::map<int, std::string>::iterator it = m.find(0);
    if (it != m.end()) {
        it->second = "abc";
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        it -> second = 1;   //OK
        it -> first = "abc" // NOT OK
        // first - key, second - value
        //const чтобы нельзя было разыменовав итератор присвоить новое значение ключу, потому что так будет ломаться дерево 
    }

}
