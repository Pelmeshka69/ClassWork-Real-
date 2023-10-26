#include <iostream>
#include <Windows.h>

using namespace std;

string question[9] = { "Який фрукт є символом Ньютона?",
                       "Який фрукт має червоний і жовтий різновид і використовується в салатах?",
                       "Який фрукт вирощується на пальмі і використовується для виробництва олії?",
                       "Який фрукт зазвичай використовується для приготування апельсинового соку?",
                       "Який фрукт дуже кислий і використовується для приготування лимонаду?",
                       "Який фрукт зазвичай використовується для приготування гуакамоле?",
                       "Який фрукт є символом тропіків і часто зображується на обкладинках журналів?",
                       "Який фрукт має тверду кірку і соковите рожеве м'ясо з чорним насінням усередині?",
                       "Який фрукт, що має гострий смак, часто використовується в суші та японській кухні?" };
string answer[9] = { "Яблуко", "Персик", "Кокос", "Апельсин", "Лимон", "Авокадо", "Пальма", "Гранат", "Імбір" };


class Tables {
private:
    string question[9];
    string answer[9];
    string displayAnswer[9];
public:
    //--------------------------------------------------------------------------
    void createGraphicsTable() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < displayAnswer[i].length(); j++) {
                cout << '|' << displayAnswer[i][j] << '|';
            }
            cout << endl;
        }
    }
    //--------------------------------------------------------------------------
    Tables(string question[], string answer[]) {
        for (int i = 0; i < 9; i++) {
            this->question[i] = question[i];
            this->answer[i] = answer[i];
            this->displayAnswer[i] = string(answer[i].length(), ' ');
        }
        createGraphicsTable();
    }
    void getQuestion() {
        for (int i = 0; i < 9; i++) {
            if (this->question[i] != "") {
                cout << i + 1 << '.' << this->question[i] << endl;
            }
        }
    }
    void playGame() {
        int questionNumber;
        string userAnswer;
        while (true) {
            getQuestion();
            cout << "Введіть номер питання: ";
            cin >> questionNumber;
            cout << question[questionNumber - 1] << endl;
            cout << "Введіть вашу відповідь: ";
            cin >> userAnswer;
            if (userAnswer == answer[questionNumber - 1]) {
                cout << "Ви правильно відповіли!" << endl;
                displayAnswer[questionNumber - 1] = answer[questionNumber - 1];
                createGraphicsTable();
                question[questionNumber - 1] = "";
                bool gameEnd = true;
                for (int i = 0; i < 9; i++) {
                    if (question[i] != "") {
                        gameEnd = false;
                        break;
                    }
                }
                if (gameEnd) {
                    cout << "Ви виграли гру!" << endl;
                    break;
                }
            }
            else {
                cout << "Неправильна відповідь. Спробуйте ще раз." << endl;
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tables game{ question,answer };
    game.playGame();
}
