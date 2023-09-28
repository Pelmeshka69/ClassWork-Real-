#include <iostream>

using namespace std;

class Bird {
public:
    string name;
    string breed;
    string color;
    float weight;
    float height;
    Bird() {
        this->breed = "";
        this->color = "";
        this->weight = 0;
        this->height = 0;
    }
};

class HomeParrot : public Bird {
public:
    bool isSpeak;
    bool trained;
    HomeParrot() {
        this->name = "";
        this->isSpeak = true;
        this->trained = true;
        this->breed = "Budgies";
        this->color = "Rainbow";
        this->weight = 0;
        this->height = 0;
    }
    void Say(string word) {
        cout << name << " says: " << word << endl;
    }

    void SetName(string newName) {
        name = newName;
    }

    void SetColor(string newColor) {
        color = newColor;
    }

    void SetBreed(string newBreed) {
        breed = newBreed;
    }

    void SetWeight(float newWeight) {
        weight = newWeight;
    }

    void SetHeight(float newHeight) {
        height = newHeight;
    }
};

class Penguin : public Bird {
public:
    bool swim;
    bool fly;
    Penguin() {
        this->name = "";
        this->breed = "Adeliae";
        this->color = "Black and white";
        this->weight = 0;
        this->height = 0;
        this->swim = true;
        this->fly = false;
    }

    void SetName(string newName) {
        name = newName;
    }

    void SetColor(string newColor) {
        color = newColor;
    }

    void SetBreed(string newBreed) {
        breed = newBreed;
    }

    void SetWeight(float newWeight) {
        weight = newWeight;
    }

    void SetHeight(float newHeight) {
        height = newHeight;
    }

    void CheckSwimAndFly() {
        if (swim && !fly) {
            cout << name << " Can swim but cannot fly." << endl;
        }
    }
};

class Chicken : public Bird {
public:
    bool fly;
    Chicken() {
        this->name = "";
        this->breed = "Meat";
        this->color = "Brown";
        this->weight = 0;
        this->height = 0;
        this->fly = false;
    }

    void SetName(string newName) {
        name = newName;
    }

    void SetColor(string newColor) {
        color = newColor;
    }

    void SetBreed(string newBreed) {
        breed = newBreed;
    }

    void SetWeight(float newWeight) {
        weight = newWeight;
    }

    void SetHeight(float newHeight) {
        height = newHeight;
    }

    void CheckSwimAndFly() {
        if (!fly) {
            cout << name << " Cannot fly." << endl;
        }
    }
};

int main() {
    HomeParrot Pit;
    cout << Pit.breed << endl;
    Pit.SetColor("Blue");
    Pit.name = "Pit";
    cout << Pit.name << endl;

    Penguin Pen;
    Pen.SetName("Pen");
    cout << Pen.name << endl;

    Chicken Chick;
    Chick.SetName("Chick");
    cout << Chick.name << endl;

    Pen.CheckSwimAndFly();   
    Chick.CheckSwimAndFly(); 

    return 0;
}
