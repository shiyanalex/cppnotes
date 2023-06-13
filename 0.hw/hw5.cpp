#include <iostream>
#include <cmath>
using namespace std;

void printArray(int* arr, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i * m + j] << '\t';
    }
        cout << endl;
    }
}

void F1(int* arr, int n, int m){
    cout<<"enter what swap and on what: " <<endl;
    int x,pos; cin>>x>>pos;
    cout<<endl;
    int temp = x;
    arr[x-1]=pos;
    arr[pos-1]=temp;
    printArray(arr, n,m);

};


void F2(int* arr, int n, int m){
    int j,c;
    cout << "Enter column: "; cin >> j;
    cout << "Enter c: "; cin >> c;
    
    for (int i = 0; i < n; i++) {
        arr[(i)*m + (j)-1] *= c;
    }
    printArray(arr, n,m);
    
}


void F3(int* arr, int n, int m){
    int i,c;
    cout << "Enter row: "; cin >> i;
    cout << "Enter c: "; cin >> c;

    for (int j = 0; j < m; j++) {
    arr[(i-1)*m + (j)] *= c;
    }
    printArray(arr, n,m);
    
}


void F4(int* arr, int n, int m){
    int a,b,temp;
    cout << "Enter first column: "; cin >> a;
    cout << "Enter second column: "; cin >> b;
    for (int i=0;i<n;i++){
        temp=arr[i*m+a-1];
        arr[i*m+a-1]=arr[i*m+b-1];
        arr[i*m+b-1]=temp;
    }
    printArray(arr, n,m);

}

void F5(int* arr, int n, int m){
    int a,b,temp;
    cout << "Enter first row: "; cin >> a;
    cout << "Enter second row: "; cin >> b;
    for (int i=0;i<m;i++){
        temp=arr[(a-1)*m+i];
        arr[(a-1)*m+i]=arr[(b-1)*m+i];
        arr[(b-1)*m+i]=temp;
    }
    printArray(arr, n,m);

}

void F6(int* arr, int n, int m){
    int a,b;
    int* res;
    res = new int[m];
    cout << "Enter first row to sum: "; cin >> a; a-=1;
    cout << "Enter second row to sum: "; cin >> b; b-=1;

    for (int i=0;i<m;i++){
        res[i]=arr[(a*m+i)+(b*m+i)+1];
    }
    for (int i=0;i<m;i++){
        cout << res[i] << '\t';
    }
}

void F7(int* arr, int n, int m){
    cout<<n<<endl; // в нашем массиве все элементы располагаются по возрастанию > в нижней строке будут всегда самые большие
    
}

int main() {
    int n,m;
    int* arr;
    cout<<"enter N and M: " <<endl;
    cin>>n>>m;
    arr = new int[n * m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i * m + j] = i * m + j + 1;
        }
    }

    printArray(arr, n,m);
    cout << endl;
    cout << endl;
//    F1(arr, n,m);
//    cout << endl;
//    cout << endl;
//    F2(arr, n,m);
//    cout << endl;
//    cout << endl;
//    F3(arr, n,m);
//    cout << endl;
//    cout << endl;
//    F4(arr, n,m);
//    cout << endl;
//    cout << endl;
//    F5(arr, n,m);
//    cout << endl;
//    cout << endl;
//    F6(arr, n,m);
//    cout << endl;
//    cout << endl;
//    F7(arr, n,m);
    
    

return 0;
}



