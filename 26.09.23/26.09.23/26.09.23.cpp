#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Player {
private:
    string name;
    int hp;
    float speed;
    float accuracy; // damage = speed * accuracy
public:
    Player(string name) {
        this->name = name;
        this->hp = 100;
        this->speed = this->hp / 10;
        this->accuracy = rand() % 3;
    }
    void newStep() { this->accuracy = rand() % 10; }
    void setHP(int hp) { this->hp = hp; }
    int damage() { return this->speed * this->accuracy; }
    string getName() { return this->name; }
    int getHP() { return this->hp; }
};

class Game {
    bool isStart = false;
    int round = 0;
    Player list[4] = { {"Max"}, {"Yan"}, {"Dima"}, {"Oleg"} };
public:
    void Start() {
        if (isStart == false) { isStart = true; }
        while (!isGameOver()) {
            nextRound();
        }
        findWinner();
    }
    void Finish() {
        if (isStart == true) {
            isStart = false;
        }
    }
    int getRound() {
        cout << this->round;
        return this->round;
    };
    void nextRound() {
        for (int i = 0; i < 4; i++) {
            if (list[i].getHP() > 0) {
                int damage = list[i].damage();
                for (int j = 0; j < 4; j++) {
                    if (i != j) {
                        int newHP = list[j].getHP() - damage;
                        if (newHP <= 0) {
                            newHP = 0;
                        }
                        list[j].setHP(newHP);
                    }
                }
            }
        }
        round++;
        printPlayersInfo();
    };
    void findWinner() {
        Player winner = list[0];
        for (int i = 1; i < 4; i++) {
            if (list[i].getHP() > winner.getHP()) {
                winner = list[i];
            }
        }
        cout << "Переможець: " << winner.getName() << " (HP: " << winner.getHP() << ")" << endl;
    }
    bool isGameOver() {
        int aliveCount = 0;
        for (int i = 0; i < 4; i++) {
            if (list[i].getHP() > 0) {
                aliveCount++;
            }
        }
        return aliveCount <= 1;
    }
    void printPlayersInfo() {
        cout << "Інформація про гравців після раунду " << round << ":" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Гравець " << list[i].getName() << " - HP: " << list[i].getHP() << endl;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    Game first;
    first.Start();

    return 0;
}
