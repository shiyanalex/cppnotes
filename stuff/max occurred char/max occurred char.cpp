#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>

using namespace std::chrono;

//wtf is this solution
/*
void for_files1(std::string& s) {
    std::fstream file;
    file.open (s);

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
            std::cout << "'" << bch << "'" << " was used " << best << " times\n";
        }
    } else {
        std::cout << "Error GG \n";
    }
} */

void for_files2(std::string s) {
    std::fstream file;
    file.open(s);

    if (file.is_open()) {
        std::cout << "File is open : \n";
        
        while (!file.eof()) {
            std::string s;
            getline(file, s);

            char bch;
            int best = 0;
            std::unordered_map<char, int> mapper;
            for (const auto c : s) {
                ++mapper[c];
                if (mapper[c] > best) best = mapper[c], bch = c;
            }
            std::cout << "'" << bch << "'" << " was used " << best << " times\n";
        }
    } else {
        std::cout << "Error GG \n";
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
    std::cout << "'" << bch << "'" << " was used " << best << " times\n";

}

int main() {
    //std::string S ="abaasdffsdknbsewrgafhdflgkjjiskjdfc";
    //for_string(S);
    //std::cout << "\n";

    std::ios_base::sync_with_stdio(false);

    auto start = high_resolution_clock::now();
    for_files2("input.txt");
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "time1 : " << duration.count() << "ms" << std::endl;

}

