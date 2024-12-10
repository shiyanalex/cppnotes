#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceNewlines(const std::string &inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Unable to open file " << inputFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << "\n\n";
    }

    inFile.close();
}

int main() {
    std::string inputFile = "input";  // Input file name

    replaceNewlines(inputFile);

    return 0;
}

