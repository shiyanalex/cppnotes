#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string s;
    std::fstream file("input");

    if (file.is_open()) {
        string in;
        string out;
        while (getline (file, in)) {
            out += in;
        }

        std::replace(out.begin(), out.end(), "\n", "\n\n"); // replace all 'x' to 'y'

        std::cout << out;
    } else {
        std::cout << "Error GG \n";
    }
}
