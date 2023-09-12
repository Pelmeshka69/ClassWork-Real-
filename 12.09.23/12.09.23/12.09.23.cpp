#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
};

Student oldStudent(Student students[], int size) {
    Student oldest = students[0];
    for (int i = 1; i < size; ++i) {
        if (students[i].age > oldest.age) {
            oldest = students[i];
        }
    }
    return oldest;
}

int main() {
    Student newList[3]{ {"Vlad",20},
                       {"Oleg", 19},
                       {"Maxim",18} };
    Student oldestStudent = oldStudent(newList, 3);

    cout << "Oldest student : " << oldestStudent.name << '\n';
    cout << "age: " << oldestStudent.age;

    return 0;
}
