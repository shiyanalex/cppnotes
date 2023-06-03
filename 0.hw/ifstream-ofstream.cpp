#include <iostream> 
#include <vector>
#include <fstream>

int main() {
    std::ifstream file("mydata.txt");

    if (file.is_open()) {
        std::cout << "File is open : \n";
        //std::cout << file.rdbuf();
        
        //using string 
        std::string name = "a";
        std::string surname = "b";
        int age = 0;

        while (!file.eof()) {
            //str = "";
            //getline(file, str);
            //std::cout << str << std::endl; 
            file >> name >> surname >> age;
        }
        
        std::cout << name << surname << age;

        /* using char 
        char ch;
        int i = 0;
        while (file.get(ch)) {
            std::cout << ch;
            ++i;
        }   std::cout << i;
        */
    } else { 
        std::cout << "error while opening file\n";
        file.close();
    }

}

/*
int main () {
    std::ofstream file;
    file.open ("codebind.txt");
    file << "Please write this text to a file.\n This text is written using C++\n";
    file.close();
    return 0;
} */
