#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Figure {
protected:
    char symbol;
public:
    char* line;
    char** box;

    Figure(string type, char symbol) {
        this->symbol = symbol;
        this->line = nullptr;
        this->box = nullptr;

        if (type == "line") {
            this->line = new char[4];
            for (int i = 0; i < 4; i++) {
                this->line[i] = this->symbol;
            }
        }
        else if (type == "box") {
            this->box = new char* [2];
            for (int i = 0; i < 2; i++) {
                this->box[i] = new char[2];
                for (int j = 0; j < 2; j++) {
                    this->box[i][j] = symbol;
                }
            }
        }
        else {
            cout << "Неверный тип фигуры: " << type << ". Пожалуйста, используйте 'line' или 'box'." << endl;
        }
    }
};

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

    void addFigure(Figure figure, int x, int y) {
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            bool canPlace = true;

            if (figure.line) {
                if (x <= 6) {
                    for (int i = 0; i < 4; i++) {
                        if (this->array[y][x + i] != ' ') {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        for (int i = 0; i < 4; i++) {
                            this->array[y][x + i] = figure.line[i];
                        }
                    }
                }
            }
            else if (figure.box) {
                if (x <= 8 && y <= 8) {
                    canPlace = true;
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 2; j++) {
                            if (this->array[y + i][x + j] != ' ') {
                                canPlace = false;
                                break;
                            }
                        }
                    }
                    if (canPlace) {
                        for (int i = 0; i < 2; i++) {
                            for (int j = 0; j < 2; j++) {
                                this->array[y + i][x + j] = figure.box[i][j];
                            }
                        }
                    }
                }
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
        cout << endl;
    }
};

int main() {
    srand(time(NULL));
    Field game;

    Figure teewee("line", 'T');
    Figure smashboy("box", 'S');
    Figure rhodeIslandZ("line", 'R');
    Figure orangeRicky("line", 'O');

    game.addFigure(teewee, 0, 0);
    game.addFigure(smashboy, 0, 3);
    game.addFigure(rhodeIslandZ, 0, 6);
    game.addFigure(orangeRicky, 0, 9);

    game.showField();

    return 0;
}




//---------------------
//|s|c| | | | | | |o|o|
//|s|c|c| | | | | |o|o|
//|s|s|c| | | | | | | |
//| | | | | | |a|a|a|a|
//| | | | | | | | | | |
//| | | |n|n|n|n| | | |
//| | | | | | | | | | |
//| | | | |l|l| | |x| |
//| | | | |l|l| | |x|x|
//| | | | | | | | | |x|
//---------------------
//|0|1|2|3|4|5|6|7|8|9|