#include <iostream>
using namespace std;

class Progression {
private:
    unsigned long first;
    unsigned long second;
public:
    Progression(unsigned long first, unsigned long second) {
        this->first = first;
        this->second = second;
    }
    unsigned long getNumberByOrdinal(unsigned int ordinal = 1) {
        if (ordinal == 1)
            return first;
        if (ordinal == 2)
            return second;
        unsigned long numberF = first, numberS = second, numberT;
        for (unsigned int i = 3; i <= ordinal; i++) {
            numberT = numberF + numberS;
            numberF = numberS;
            numberS = numberT;
        }
        return numberS;
    }
};

int main() {
    Progression progression(1, 2);
    cout << progression.getNumberByOrdinal(5) << endl; 
    return 0;
}
