#include <iostream>
#include <set>
#include <string>
using namespace std;
int n;

int finalPosition(std::string commands) {
    int position = 0;
    int direction = 1;  // 1: вправо, -1: влево

    for (char command : commands) {
        if (command == 'F') position += direction;  // Движение в текущем направлении
        else if (command == 'L') direction = -1;
        else if (command == 'R') direction = 1;
    }
    return position;
}

set<int> Positions(string& commands) {
    set<int> positions;

    for (int i = 0; i < n; ++i) {
        string newCommands = commands;
        char original = newCommands[i];

        for (char ch : {'F', 'L', 'R'}) {
            if (ch != original) {
                newCommands[i] = ch;
                positions.insert(finalPosition(newCommands));
            }
        }
    }
    return positions;
}

int main() {
    cin >> n;
    string commands;
    cin >> commands;
    set<int> result = Positions(commands);
    cout << result.size();
    return 0;
}

