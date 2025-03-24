#include <iostream>
#include <vector>

std::vector<int> random1;

void start() {
    srand(time(NULL));          // Initialize random number generator.
    random1.push_back((std::rand()% 10)+1);
    while (random1.size() < 4) {
        int r = (std::rand()% 10)+1;
        if (std::find(random1.begin(), random1.end(), r) == random1.end()) {
            random1.push_back(r);
        }
    }

    //its for debug 
    /*
    for (int x : random1) {
       std::cout << x << " ";
    }
    std::cout << "\n";
    */
}

void game() {
    std::cout << "Hello, and welcome to my modification of Bulls_and_Cows Game\n";
    std::cout << "You need to guess 4 numbers correctly to win \n";

    int lives = 5;
    while (lives != 0 && random1.size() != 0) {
        int key;
        std::cin >> key;
        auto it = std::find(random1.begin(), random1.end(), key);
        if (it == random1.end()) {
            lives--;
            std::cout << "thats a miss\nyou have " << lives << " tries left\n";
        } else {
            std::cout << "you got this\n";
            random1.erase(it);
            continue;
        }
    }
    
    if (lives == 0) {
        std::cout << "OMAGALUL SO BAD\n";
    } else {
        std::cout << "Congrats, you win\n";
    }

}

void original() {
    std::cout << "\nEnter your values : \n"; 
    std::istream_iterator<int> it(std::cin);
    std::vector<int> input;
    for (int i = 0; i < 4; ++i) {
        if (i != 0) ++it;
        input.push_back(*it);
    }
 
    int Bulls = 0;
    int Cows = 0;
    
    for (int i = 0; i < 4; ++i) {
        if (std::find(random1.begin(), random1.end(), input[i]) != random1.end()) {
            Cows ++;
        }
        if (random1[i]==input[i]) {
            Bulls ++;
        }
    }

    Cows = Cows - Bulls;  
    std::cout << "\nBulls : " << Bulls << "\nCows  : " << Cows << "\n";
}

int main() {

    start();
    game();
    //original();
    
}
