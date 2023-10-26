#include <iostream> 
#include <vector>

// RLE - Run-Length Encoding

void RLE (std::string& a) {
    typedef std::pair<char, int> PAIR;

    std::vector<PAIR> b;
    int pos = 1;
    int len = a.length();
    for (int i = 0; i < len; i++) {
        if (a[i] == a[i+1]) ++pos;
        else {
            b.emplace_back(std::make_pair(a[i], pos));
            pos = 1;
        }
    }
    
    for (int i = 0; i < b.size(); i++) {
        std::cout << b[i].first << b[i].second;
    }
}

int main() {
    
    std::string S("AAABBBAAAAABBBEBCCCDDDDYYYSSSPSSSLLLLL");
    // сжать чтобы было A3B3A5B3EBC3D4Y3S3pS3L5
    RLE(S);

}
