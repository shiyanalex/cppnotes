#include <iostream>
#include <fstream>
#include <set>

int main() {
    std::fstream fin("input.txt");
    std::set<std::string> words;
    std::string word;

    while (fin >> word) {
        words.insert(word);
    }

    std::cout << words.size() << std::endl;

}
