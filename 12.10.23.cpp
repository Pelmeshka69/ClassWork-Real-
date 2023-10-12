#include <iostream>

using namespace std;

class Field {
public:
    char** array = new char* [10];
    Field() {
        for (int i = 0; i < 10; i++) {
            this->array[i] = new char[10];
            for (int j = 0; j < 10; j++) {
                this->array[i][j] = ' ';
            }
        }
    }
    void showField() {
        for (int i = 0; i < 30; i++) {
            cout << '-';
        }
        cout << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << '|' << array[i][j] << '|';
            }
            cout << endl;
        }
        for (int i = 0; i < 30; i++) {
            cout << '-';
        }
    }
};

void drawLine(Field& field) {
    for (int i = 0; i < 4; i++) {
        field.array[i][i] = 'A';
    }
}

void drawTank(Field& field) {
    for (int i = 0; i < 3; i++) {
        field.array[4][i] = 'B';
        field.array[5][i] = 'B';
    }
}

void drawUpsideDown(Field& field) {
    for (int i = 0; i < 2; i++) {
        field.array[9 - i][i] = 'D';
    }
}

void drawBox(Field& field) {
    for (int i = 3; i < 4; i++) {
        for (int j = 3; j < 4; j++) {
            field.array[i][j] = 'C';
        }
    }
}

void drawLightning(Field& field) {
    for (int i = 0; i < 2; i++) {
        field.array[i][4 - i] = 'E';
    }
}

int main() {
    Field field;

    drawLightning(field);

    field.showField();
}
