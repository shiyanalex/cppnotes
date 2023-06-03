#include <iostream>
using namespace std;

struct Array2D{
    int h;
    int w;
    float** v;
};

void printArray(Array2D& arr) {
    for (int i = 0; i < arr.h; i++) {
        for (int j = 0; j < arr.w; j++) {
            arr.v[i][j] = i * arr.w + j;
            cout << arr.v[i][j] << "\t";
        }
    cout << endl;
    }
}

Array2D NewArray2D (int h, int w) {
    Array2D res;
    if (h > 0 && w > 0) {
        res.h = h;
        res.w = w;
        res.v = new float* [res.h];
        for (int i = 0; i < res.h; i++) {
            res.v[i] = new float[res.w];
        }
    }
    
    else {
        res.h = 0;
        res.w = 0;
        res.v = NULL;
    }
return res;
}

void DeleteArray2D(Array2D& arr) {
    for (int i = 0; i < arr.h; i++){
        arr.v[i]=0;
    }
    //delete[]arr.v;
    //delete[] arr.v;
    //arr.v=NULL;
    printArray(arr);

}

void ResizeArray2D(Array2D& arr){
    int nh, nw;
    cout << "Enter new h = "; cin >> nh; cout << "Enter new w = "; cin >> nw;

    DeleteArray2D(arr);
    arr = NewArray2D (nh, nw);
    
}

int main() {
    Array2D arr1;
    int h, w;
    cout << "Enter h = "; cin >> h; cout << "Enter w = "; cin >> w;
    arr1 = NewArray2D(h, w);
    for (int i = 0; i < arr1.h; i++) {
        for (int j = 0; j < arr1.w; j++) {
            arr1.v[i][j] = i * arr1.w + j;
        }
    }
    cout << "Array:" << endl;
    printArray(arr1);
//    DeleteArray2D(arr1);
    cout << endl;
    cout << endl;
    ResizeArray2D(arr1);
    return 0;
}
