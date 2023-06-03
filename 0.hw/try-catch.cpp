#include <iostream>
#include <cmath>

using namespace std ;
    
int main() {
    double a,b;
    cout << "enter 2 numbers : " << '\n';
    cin >> a >> b;

    try {
        if(b == 0) throw 1;
            cout << a/b << '\n';
        
        if(a == 0) throw 0.5;
            cout << sqrt(a/b) << '\n';

        if(a == b) throw "L";
            
    }

    catch(int) {
        cout<< "DELENIE NA 0" <<endl;
    }

    catch(double){
        cout << "A = 0" << endl;
    }
        
    catch(...){ 
        cout<< "error!!" <<endl;
    }

    cout<<"END EZ"<<'\n';

    return 0;
}
