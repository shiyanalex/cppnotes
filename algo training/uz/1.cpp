#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int longest(string& s) {
    int max_len = 0;
    int curr_len = 0;

    for (auto i : s) {
        if (i != ' ' && i != ',') {
            ++curr_len;
        } else {
            curr_len = 0;
        }
        max_len = std::max(max_len, curr_len);
    }
    return max_len;
}

vector<string> split_sentence(string sen) {
    vector<string> words;
    string word;
    
    for (char c : sen) {
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else if (c == ',') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            words.push_back(",");
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

void format_text(string s, int len) {
    vector<string> words = split_sentence(s);
    string out;

    for (auto it = words.begin(); it != words.end(); ++it) {
        string w = *it;
        auto it2 = it + 1;
        string next = (it2 != words.end()) ? *it2 : "";

        if (out.size() + w.size() <= len) {
            if (next == ",") {
                out += w;
            } else {
                out += w + " ";
            }
        } 
        else {
            if (out.back() == ' ') out.pop_back();
            cout << out << "\n";
            out.clear();
            --it;
        }
    }

    if (!out.empty()) {
        if (out.back() == ' ') out.pop_back();
        cout << out << "\n";
    }
}

int main() {
    string s;
    getline(cin, s);
    cout << longest(s) << "\n";
    int len = longest(s) * 3;
    format_text(s, len);
    return 0;
}

