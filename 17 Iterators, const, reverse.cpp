#include <iostream>
#include <vector>
#include <list>

// Контейнер — набор однотипных элементов
// Итератор — унифицированный доступ к последовательности (например контейнеру) 
// оверолл это обобщение / просто возможность ходить по послдовательности, которая не обязательно хранится в контейнере 

// последовательные контейнеры — вектор (vector), двусвязный список (list), дэк (deque), forward_list - list только с доступом в прямом направлении
// ассоциативные контейнеры — множества (set и multiset ), хэш-таблицы (map и multimap);
// псевдо контейнеры — битовые маски (bitset), строки (string и wstring), массивы (valarray);

// Виды итераторов  1) однонаправленные (помню в одну сторону)
// 					2) двунаправленные  (вперед-назад быстро, но прибавлять нельзя)
// 					3) с произвольным доступом 

// Categories of iterators : 
// InputIterator() <- ForwardIterator (++) <- BiderctionalIterator (--) <- RandomAccessIterator (+n, -n, it1 - it2, <, >)
// istream_iterator	  forward_list 				list							vector 
//  				  unordered_map/set 		map / set 						deque 

// Почему итераторы лучше индексов? Хотя бы потому, что итератор можно сделать константной ссылкой, что гарантирует невозможность испортить массив. 
// + не ко всем контейнерам можно обратиться через индекс 

// У вектора беды с итераторами при изменении, нельзя ничего вставлять и менять из вектора чтобы не сломать итератор из за переолокации 

// Const iterators - итераторы которые не позволяют менять объект под собой

template <typename T>
class Vector {
	T* arr;
	size_t sz = 0;

public:
	template <bool IsConst>
	struct common_iterator {
	private: 
		std::conditional_t<IsConst, const T*, T*> ptr; 	// первый если тру, второй если фолс 
	public: 
		common_iterator(T* prt) : ptr(prt) {}

		common_iterator& operator*() {
			return *ptr;
		}

		common_iterator& operator->() {
			return ptr;
		}

		common_iterator& operator++() {
			++ptr;
			return *this;
		}
	};

	// using - другое название для типа 
	using iterator = common_iterator<true>;
	using const_iterator = common_iterator<false>;

	//Vector(const int* s): sz(strlen(s)), arr(new char[sz]);
	
    Vector(std::initializer_list<int> lst): sz(lst.size()), arr(new int[sz]) {	
		std::copy(lst.begin(), lst.end(), arr);	
	}

	iterator begin() const {
		return common_iterator(arr);
	}
	
	iterator end() const {
		return common_iterator(arr + sz);
	}

	// using reverse_iterator = std::reverse_iterator<iterator>;
	// using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	// reverse_iterator rbegin() const {
	// 	return reverse_iterator(arr+sz-1);
	// }

	// reverse_iterator rend() const {
	// 	return reverse_iterator(arr-1);
	// }
}; 

int main() {
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	//std::cout << v[3];	// Error с листами

    auto it = v.cbegin(); 
    //*it = 0;
    
}
