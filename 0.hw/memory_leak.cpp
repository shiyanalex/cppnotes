#include <iostream>

int main() {

   double *ptr = new double(3.14);
   int a[] = {1,2,3,4,5};			// массив на стейке поэтому нельзя созать a[100000]
   int* pa = new int[100];			// new int создает динамический массив, это отдельная память которой больше
   //delete[] pa;

}
