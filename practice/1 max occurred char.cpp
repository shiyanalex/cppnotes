#include <iostream>
#include <fstream>

void for_files(std::ifstream& file) {
    if (file.is_open()) {
        std::cout << "File is open : \n";
        std::string s;
        while (!file.eof()) {
            getline(file, s);
            int best = 0;
            char bch;

            for (int i = 0; i != s.size(); ++i) {
                int current = 0;
                char ch = s[i];

                for (int j = 0; j != s.size(); ++j) {
                    if (s[i] == s[j]) ++current;
                }
                if (current > best) best = current, bch = ch;
            }
            std::cout << "'" << bch << "'" << " was used " << best << " times";
        }
    } else {
        std::cout << "Error GG";
    }
}


void for_string(std::string& s) {
    int best = 0;
    char bch;
    for (int i = 0; i != s.size(); ++i) {
        int current = 0;
        char ch = s[i];
        for (int j = 0; j != s.size(); ++j) {
            if (s[i] == s[j]) ++current;
        }
        if (current > best) best = current, bch = ch;
    }
    std::cout << "'" << bch << "'" << " was used " << best << " times";

}

int main() {
    std::string S ="abaasdffsdknbsewrgafhdflgkjjiskjdfc";
    for_string(S);
    std::cout << "\n";
    //for_files("output-onlinefiletools.txt");

}

