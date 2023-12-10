#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Weapon {
public:
    virtual string getName() = 0;
    unsigned short damage;
    unsigned short weight;
    unsigned short numberOfCartridgesInTheClip;
    unsigned short numberOfClips;
    unsigned short accuracy;
    double rateOfFire;

    void setDamage(unsigned short newDamage) { damage = newDamage; }
    void setAccuracy(unsigned short newAccuracy) { accuracy = newAccuracy; }


    unsigned short getDamage() { return damage; }
    unsigned short getWeight() { return weight; }
    unsigned short getNumberOfCartridgesInTheClip() { return numberOfCartridgesInTheClip; }
    unsigned short getNumberOfClips() { return numberOfClips; }
    unsigned short getAccuracy() { return accuracy; }
    double getRateOfFire() { return rateOfFire; }
};



class Empty : public Weapon {
public:
    string getName() override { return "Empty"; }
    Empty() {
        this->damage = 5;
        this->weight = 0;
        this->numberOfCartridgesInTheClip = 1000;
        this->numberOfClips = 0;
        this->accuracy = 60;
        this->rateOfFire = 0.9;
    }
};

class Glock : public Weapon {
public:
    string getName() override { return "Glock"; }
    Glock() {
        this->damage = 15;
        this->weight = 25;
        this->numberOfCartridgesInTheClip = 17;
        this->numberOfClips = 5;
        this->accuracy = 60;
        this->rateOfFire = 0.7;
    }
};

class AK47 : public Weapon {
public:
    string getName() override { return "AK47"; }
    AK47() {
        this->damage = 55;
        this->weight = 90;
        this->numberOfCartridgesInTheClip = 30;
        this->numberOfClips = 4;
        this->accuracy = 70;
        this->rateOfFire = 0.9;
    }
};

class M4A1 : public Weapon {
public:
    string getName() override { return "M4A1"; }
    M4A1() {
        this->damage = 50;
        this->weight = 80;
        this->numberOfCartridgesInTheClip = 20;
        this->numberOfClips = 4;
        this->accuracy = 80;
        this->rateOfFire = 0.9;
    }
};

class ShotGun : public Weapon {
public:
    string getName() override { return "ShotGun"; }
    ShotGun() {
        this->damage = 90;
        this->weight = 80;
        this->numberOfCartridgesInTheClip = 7;
        this->numberOfClips = 4;
        this->accuracy = 40;
        this->rateOfFire = 0.6;
    }
};

class Character {
protected:
    unsigned short hp = 100;
    unsigned short speed = 255;
    unsigned short armor = 0; 
    unsigned short stamina = 0;
    Weapon* weapon;

    
    void getW() {
        int weaponType = rand() % 5;
        switch (weaponType) {
        case 0:
            this->weapon = new Empty();
            break;
        case 1:
            this->weapon = new Glock();
            break;
        case 2:
            this->weapon = new AK47();
            break;
        case 3:
            this->weapon = new M4A1();
            break;
        case 4:
            this->weapon = new ShotGun();
            break;
        }
    }

public:
    Character() {
        getW();
    }


    void openFire(Character& character) {
        unsigned short actualDamage = weapon->getDamage();
        if (character.armor > 0) {
            actualDamage -= (actualDamage * character.armor / 100); 
        }
        character.hp -= actualDamage;
    }

    
    void setArmor(unsigned short newArmor) { armor = newArmor; }

    
    unsigned short getHp() { return hp; }
    string getWeaponName() { return weapon->getName(); }

    ~Character() {
        delete weapon;
    }
};

class Player : public Character {
protected:
    string name;
public:
    Player(string name) : Character() {
        this->name = name;
    }
    string getName() { return this->name; }
};

int main() {
    srand(time(0));
    Player first("Player 1"), second("Player 2");
    cout << first.getName() << " Gun: " << first.getWeaponName() << endl;
    cout << second.getName() << " Gun: " << second.getWeaponName() << endl;
    while (first.getHp() > 0 && second.getHp() > 0) {
        first.openFire(second);
        if (second.getHp() > 0) {
            second.openFire(first);
        }
    }
    if (first.getHp() > 0) {
        cout << first.getName() << " Won!" << endl;
    }
    else {
        cout << second.getName() << " Won!" << endl;
    }
}
