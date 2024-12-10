#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;

int finalPosition(const string& commands) {
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

    // Вычисляем финальную позицию для исходной команды
    positions.insert(finalPosition(commands));

    for (int i = 0; i < n; ++i) {
        char original = commands[i];
        // Вычисляем текущую позицию до изменения
        int basePosition = finalPosition(commands);
        int direction = (original == 'F') ? 1 : (original == 'L' ? -1 : 1);
        
        for (char ch : {'F', 'L', 'R'}) {
            if (ch != original) {
                // Определяем новую позицию
                int modifiedPosition = basePosition;

                // Корректируем позицию на основе замены
                if (original == 'F') {
                    if (ch == 'L') modifiedPosition -= 1; // Левый поворот
                    else if (ch == 'R') modifiedPosition += 1; // Правый поворот
                } else if (original == 'L') {
                    if (ch == 'F') modifiedPosition += 1; // Вперед
                    else if (ch == 'R') modifiedPosition -= 1; // Вправо
                } else if (original == 'R') {
                    if (ch == 'F') modifiedPosition -= 1; // Вперед
                    else if (ch == 'L') modifiedPosition += 1; // Влево
                }

                // Сохраняем новую позицию
                positions.insert(modifiedPosition);
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
    cout << result.size(); // Выводим количество уникальных конечных позиций
    
    return 0;
}

