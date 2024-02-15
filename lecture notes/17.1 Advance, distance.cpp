#include <iostream>
#include <list>
#include <vector>

// Advance и Distance - с random access контейнерами работает за константное время, с остальными за линейное 
// Поэтому надо проверить если итератор рандом аксесс сделать одно - иначе другое 
// как проверить категорию итератора на рандом аксесс? 

// Advance
/*
template <typename Iterator, typename IterCategory>
void my_advance_helper(Iterator& iter, int n, IterCategory) {
    for (int i = 0; i < n; ++i, ++iter);
}

template <typename Iterator>
void my_advance_helper(Iterator& iter, int n, std::random_access_iterator_tag) {
    iter +=n;
}

template <typename Iterator>
void my_advance (Iterator& iter, int n) {
    my_advance_helper(iter, n, typename std::iterator_traits<Iterator>::iterator_category());
} */

// since c++11 there is constexpr
template <typename Iterator>
void my_advance (Iterator& iter, size_t n) { 
    //if constexpr (std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>)
    //TODO is_base_of / how tf does iterator_traits::iterator_category works?
    if constexpr (std::is_base_of_v<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>)
        iter += n;
    for (int i = 0; i < n; ++i, ++iter);
    
}

// Distance
template <typename Iterator, typename IterCategory>
void my_distance_helper(Iterator& iter1, Iterator& iter2, IterCategory) {
    int i = 0;
    while (iter1 != iter2) {
        ++i;
        ++iter1;
    }
    std::cout << i;
}

template <typename Iterator>
void my_distance_helper(Iterator& iter1, Iterator& iter2, std::random_access_iterator_tag) {
    std::cout << iter2 - iter1;
}
template <typename Iterator>
void my_distance (Iterator& iter1, Iterator& iter2) {
    my_distance_helper(iter1, iter2, typename std::iterator_traits<Iterator>::iterator_category());
}

int main () {

    //Advance
    std::list<int> v{1,2,3,4,5,6,7,8,9,10};
    //std::list<int>::iterator it = v.begin();
    auto it = v.begin();
    //std::advance(it, 3);
    my_advance(it, 3);
    std::cout << *it;
    std::cout << "\n";


    //Distance
    std::list<int>::iterator it2 = v.end();
    it2--;
    //std::cout << std::distance(it, it2);
    my_distance(it, it2);
    std::cout << "\n";


}
