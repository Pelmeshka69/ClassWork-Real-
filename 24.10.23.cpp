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
public:
    Tables(string question[], string answer[]) {
        for (int i = 0; i < 9; i++) {
            this->question[i] = question[i];
            this->answer[i] = answer[i];
        }
    }
    void getQuestion() {
        for (int i = 0; i < 9; i++) {
            cout << i + 1 << '.' << this->question[i] << endl;
        }
    }
    void guessAnswer() {
        string userAnswer;
        int questionNumber;
        cout << "Введіть номер питання, на яке ви хочете відповісти: ";
        cin >> questionNumber;
        if (questionNumber > 0 && questionNumber <= 9) {
            cout << questionNumber << ". Введіть вашу відповідь на питання: '" << this->question[questionNumber - 1] << "'" << endl;
            cin >> userAnswer;
            if (userAnswer == this->answer[questionNumber - 1]) {
                cout << "Ви правильно відповіли!" << endl;
            }
            else {
                cout << "Вибачте, але це неправильна відповідь." << endl;
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tables game{ question,answer };
    game.getQuestion();
    game.guessAnswer();
}
