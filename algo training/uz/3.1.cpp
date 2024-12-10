#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n; // Длина строки команд

// Вычисляем финальную позицию для строк, изменённых на уровне команд
int finalPosition(const string& commands, const vector<int>& prefix_positions, const vector<int>& directions) {
    int position = 0;
    int direction = 1;  // Вправо по умолчанию
    
    // Вычисляем позицию на основе направлений и команды
    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == 'F') {
            position += direction;
        } else if (commands[i] == 'L') {
            direction = -1;
        } else if (commands[i] == 'R') {
            direction = 1;
        }
    }
    return position;
}

set<int> OptimizedPositions(string& commands) {
    set<int> positions; // Множество для уникальных позиций

    vector<int> prefix_positions(n + 1, 0);  // Префиксные позиции
    vector<int> directions(n + 1, 1);        // Направления (1 = вправо, -1 = влево)

    // Шаг 1: Предварительное вычисление префиксных данных
    int position = 0, direction = 1; // Текущая позиция и направление

    for (int i = 0; i < n; ++i) {
        if (commands[i] == 'F') {
            position += direction;
        } else if (commands[i] == 'L') {
            direction = -1;
        } else if (commands[i] == 'R') {
            direction = 1;
        }
        prefix_positions[i + 1] = position;
        directions[i + 1] = direction;
    }

    // Шаг 2: Рассматриваем замену каждой команды на 'F', 'L' или 'R'
    for (int i = 0; i < n; ++i) {
        char original = commands[i];
        for (char ch : {'F', 'L', 'R'}) {
            if (ch != original) {
                // Пробуем изменить команду
                commands[i] = ch;
                
                // Шаг 3: Пересчитываем позицию только для изменённой команды
                positions.insert(finalPosition(commands, prefix_positions, directions));
            }
        }
        commands[i] = original; // Восстанавливаем исходное значение
    }
    return positions;
}

int main() {
    cin >> n;
    string commands;
    cin >> commands;

    set<int> result = OptimizedPositions(commands);
    cout << result.size() << endl; // Выводим количество уникальных конечных позиций
    return 0;
}

