#include <iostream>
#include <bitset>
using namespace std;
  
// бинарные сдвиги 
// шаблон не нужен 
// как передать адрес переменной 

void bin(long n) {
    long i;
    for (i = 1 << 7; i > 0; i = i / 2) {
      if((n & i) != 0) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
}
 
int main(void) {
    int x = 12;
    char ch = 18;
    double d = 12;
    std::cout << "using bitset :\n";
    std::cout << std::bitset<8>(x) << std::endl;
    std::cout << std::bitset<8>(ch) << std::endl;
    std::cout << std::bitset<8>(d) << std::endl;
    std::cout << "code from internet :\n";
    bin(x); std::cout<<"\n";
    bin(ch); std::cout<<"\n";
    bin(d);
}
