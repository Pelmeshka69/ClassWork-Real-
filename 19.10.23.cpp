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
    void createGraphicsTable(string answer[]) {
        int spaceCout = 0;
        int findingChar = 0;
        for (int i = 0; i < answer[0].length(); i++) {
            for (int j = 0; j < answer[1].length(); j++) {
                if (answer[0][i] == answer[1][j]) {
                    spaceCout = i;
                    findingChar = j;
                    for (int k = j; k != 0; k--) {
                        for (int q = 0; q < spaceCout; q++) {
                            cout << "   ";
                        }
                        cout << "| |" << endl;
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < answer[0].length(); i++) {
            cout << '|' << " " << '|';
        }
        cout << endl;
        for (int i = answer[1].length(); i > findingChar + 1; i--) {
            for (int q = 0; q < spaceCout; q++) {
                cout << "   ";
            }
            cout << "| |" << endl;
        }
    }
    Tables(string question[], string answer[]) {
        for (int i = 0; i < 9; i++) {
            this->question[i] = question[i];
            this->answer[i] = answer[i];
        }
        createGraphicsTable(answer);
    }
    void getQuestion() {
        for (int i = 0; i < 9; i++) {
            cout << i + 1 << '.' << this->question[i] << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tables game{ question,answer };
    game.getQuestion();
}
