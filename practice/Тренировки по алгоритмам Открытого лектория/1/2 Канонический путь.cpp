#include <iostream>

// Канонический путь (not finished)

int main() {

    std::string in;

	getline (std::cin, in);

    bool running = true;
    
    while (running) {
        std::string s1 = "/./";
        if (in.find(s1) != std::string::npos) {
            int pos = in.find(s1);
            in.replace(pos, 3, "/");
        }
        std::string s2 = "//";
         if (in.find(s2) != std::string::npos) {
            int pos = in.find(s2);
            in.replace(pos, 2, "/");
        }        
        std::string s3 = "/../";
         if (in.find(s3) != std::string::npos) {
            auto pos = in.find(s3);
            if (pos = in.begin()) {
                in.replace(pos, 4, "/");
            } else {
                prev = in.find("/", pos, in.rbegin());
            }
        }
        //else {}
            running = false;
            std::cout << in;

    }
    
}

