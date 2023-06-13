#include <iostream>
#include <vector>
#include <list>

struct IsEven {
    bool operator()(int x) const {
        return x%2 == 0;
    }
};

template<typename Container>
class back_insert_iterator {
    Container& container;

public: 
    back_insert_iterator(Container& container) : container(container) {}

    back_insert_iterator<Container>& operator++() {
        return *this;
    }
    
    back_insert_iterator<Container>& operator*() {
        return *this;
    }

    back_insert_iterator<Container>& operator=(const typename Container::value_type& value){
        container.push_back(value);
        return *this;
    }
};


template<typename Container>
back_insert_iterator<Container> my_back_inserter(Container& container){
    return back_insert_iterator<Container>(container);
}

int main() {

	std::list<int> l{1,2,3,4,5,6,7,8,9,10};
    
    std::vector<int>v;

    //std::copy_if(l.begin(), l.end(), back_inserter(v), IsEven());
    std::copy_if(l.begin(), l.end(), my_back_inserter(v), IsEven());

	for (int x : v)
        std::cout << x;
}
