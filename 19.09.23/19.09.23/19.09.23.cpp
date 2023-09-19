#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
string nameList[] = { "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah", "Ivy", "Jack" };

class Student {
public:
    string name;
    int mathAssessment;
    int physicsAssessment;
};

class SchoolClass {
public:
    Student allStudents[26];
    string randomNames[10];
    void generateStudents() {
        srand(time(0));
        for (int i = 0; i < 26; i++) {
            allStudents[i].name = nameList[rand() % 10];
            allStudents[i].mathAssessment = rand() % 100 + 1;
            allStudents[i].physicsAssessment = rand() % 100 + 1;
        }
    }
    Student getBestStudent() {
        int maxAverage = 0;
        Student bestStudent;
        for (int i = 0; i < 26; i++) {
            int average = (allStudents[i].mathAssessment + allStudents[i].physicsAssessment) / 2;
            if (average > maxAverage) {
                maxAverage = average;
                bestStudent = allStudents[i];
            }
        }
        return bestStudent;
    }
    double getClassAverage() {
        double totalAverage = 0;
        for (int i = 0; i < 26; i++) {
            totalAverage += (allStudents[i].mathAssessment + allStudents[i].physicsAssessment) / 2.0;
        }
        return totalAverage / 26;
    }
};
int main() {
    SchoolClass myClass;
    myClass.generateStudents();
    cout << "Best student: " << myClass.getBestStudent().name << endl;
    cout << "GPA: " << myClass.getClassAverage() << endl;
    return 0;
}

