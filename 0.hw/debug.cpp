#include <iostream>

void f1() {
    int *px = NULL;
    *px = 5;
}

void f2() {
    f1();
}

int main() {
    
    f2();

}
