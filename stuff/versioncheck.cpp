#include<iostream>

int main() {
    
   if (__cplusplus > 201703L)
      std::cout << "C++20";
   else if (__cplusplus == 201703L)
      std::cout << "C++17";
   else if (__cplusplus == 201402L)
      std::cout << "C++14";
   else if (__cplusplus == 201103L)
      std::cout << "C++11";
   else if (__cplusplus == 199711L)
      std::cout << "C++98";
   else
      std::cout << "pre-standard C++";

}
