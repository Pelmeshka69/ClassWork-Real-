#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int age;
};

int main() {
    Student newList[3]{ {"Vlad",20},
                       {"Oleg", 15},
                       {"Maxim",18} };

    int sortList = sizeof(newList) / sizeof(newList[0]);

    for (int i = 0; i < sortList - 1; ++i) {
        for (int j = 0; j < sortList - i - 1; ++j) {
            if (newList[j].age > newList[j + 1].age) {
                swap(newList[j], newList[j + 1]);
            }
        }
    }
    for (int i = 0; i < sortList; ++i) {
        cout << "Name: " << newList[i].name << ", Age: " << newList[i].age << '\n';
    }

    return 0;
}
