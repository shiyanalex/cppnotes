#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::string text;
    std::getline(std::cin, text);
    
    // Replace ',' with ', '
    size_t pos = 0;
    while ((pos = text.find(',', pos)) != std::string::npos) {
        text.replace(pos, 1, ", ");
        pos += 2; // Move past the new ', '
    }

    std::istringstream iss(text);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // Combine words with commas
    for (size_t i = 0; i < words.size(); ) {
        if (words[i] == ",") {
            words[i - 1] += words[i];
            words.erase(words.begin() + i);
        } else {
            ++i;
        }
    }

    size_t max_line_len = 0;
    for (const auto& w : words) {
        max_line_len = std::max(max_line_len, w.length() - (w.back() == ',' ? 1 : 0));
    }
    max_line_len *= 3;

    std::vector<std::string> lines;
    std::string cur_line;
    for (const auto& word : words) {
        bool space_count = !cur_line.empty();
        if (cur_line.length() + word.length() + space_count <= max_line_len) {
            cur_line += (space_count ? " " : "") + word;
        } else {
            lines.push_back(cur_line);
            cur_line = word;
        }
    }
    lines.push_back(cur_line);

    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    return 0;
}


