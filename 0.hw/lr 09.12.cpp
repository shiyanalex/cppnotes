#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
 
class Student {
private:
    string name;
    string surname;
    int grade;
 
public:
    Student(string name, string surname, int grade): name(name), surname(surname), grade(grade) {};
 
    Student& operator=(const Student& student) {
        name = student.name;
        surname = student.surname;
        grade = student.grade;
        return *this;
    }
 
    friend ostream& operator<<(ostream& stream, const Student& student) {
        stream << "   Name:" << setw(10) << student.name;
        stream << "   Surname:" << setw(10) << student.surname << endl;
        return stream;
    }
};

void Init(vector<Student>& students) {
    students.emplace_back("Vasiliy", "Petrov", 2);
    students.emplace_back("Trololo", "Ololoev", 4);
    students.emplace_back("Ololo", "Trololoev", 5);
    students.emplace_back("Agent", "K", 1);
    students.emplace_back("X", "Axis", 3);
    students.emplace_back("Temkasky", "C-Man", 2);
}
 
void Print(const vector<Student>& students) {
    for (const Student& student : students)
            cout << student;

}
 
int main(){
    vector<Student> students;
    Init(students);

    cout << "Students list: :" << endl;
    Print(students);

}



