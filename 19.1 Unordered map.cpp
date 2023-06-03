#include<iostream>
// Unordered map - это по сути 2 вещи - массив и лист одновременно и в массиве хранятся указатели на элементы этого листа 
//
// Load factor - average number of elements in the bucket
// Max_load_factor - if load factor exceeds it whole map rehash (default 1)
// Rehash - very expensive operation (and complicated to do with exeption safety)
// 
template <typename Key, typename Value, typename Hash = std::hash<Key>>
    typename Equal = std::equal_to<Key>>;

class unordered_map {
    
    struct Node {
        pair<const key, value> kv;
        size_t cached_hash;
        Node* next;
        Node* prev;
        Node* end
    };
public: 
    


};



int main() {




