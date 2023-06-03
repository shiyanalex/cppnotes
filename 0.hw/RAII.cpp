#include <iostream>

// RAII idiom is actually very simple, it means that any resource allocation (acquisition) is done in object constructor
// and deallocation respectively in destructor, in other words resource acquisition must succeed for initialization to succeed. 
// This method guarantees that sources are held only while object is alive. Therefore, there are no object or resource leaks
// некоторый ресурс захватывается в конструкторе объекта, и освобождается в его деструкторе. 
class TelephoneLine {
public: 
    void MakeLineBusy() {
        std::cout << "Line busy \n";        
    }
    void ReleaseLine() {
        std::cout << "Line is free \n";
    }
};

class TelephoneCall {
private: 
    TelephoneCall (const TelephoneCall&);

    TelephoneCall& operator=(const TelephoneCall&) {
        // Realisation of Assignment operator
    };
    TelephoneLine * telephoneLine;
public: 
    TelephoneCall () {
        telephoneLine = new TelephoneLine();
        telephoneLine->MakeLineBusy();
    }

    ~TelephoneCall () {
        telephoneLine->ReleaseLine();
        delete telephoneLine;
    }
};

int main() {
    {
        std::cout << "lets make a call! \n";
        TelephoneCall call;
        std::cout << "This was a nice conversation, bye babe\n";
    }
    std::cout << "zzzz\n";

}
