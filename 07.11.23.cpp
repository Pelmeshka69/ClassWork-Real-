#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

class Morse {
public:
    vector<string> letters = { "À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "×", "Ø", "Ù", "Ü",
                               "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê", "ë", "ì", "í", "î", "ï", "ð", "ñ", "ò", "ó", "ô", "õ", "ö", "÷", "ø", "ù", "ü" };
    vector<string> morse = { ".-", "-...", ".--", "--.", "-..", ".", "...-", "--..", "..", ".---", "-.-", ".-..",
                            "--",
                            "-.", "---", ".--.", ".-.", "...", "-", "..-", "..-.", "....",
                            "-.-.", "---.", "----",
                            "--.-",
                            ".-", "-...", ".--", "--.", "-..", ".", "...-", "--..", "..", ".---", "-.-", ".-..",
                            "--",
                            "-.", "---", ".--.", ".-.", "...", "-", "..-", "..-.", "....",
                            "-.-.", "---.", "----",
                            "--.-" };
};

class InformationEncoding {
public:
    string encode(string sentence, Morse morse) {
        string encoded = "";
        for (char& c : sentence) {
            string letter(1, c);
            if (letter[0] >= 'à' && letter[0] <= 'ÿ') {
                letter[0] -= 32;
            }
            for (int i = 0; i < morse.letters.size(); i++) {
                if (morse.letters[i] == letter) {
                    encoded += morse.morse[i] + ' ';
                    break;
                }
            }
        }
        return encoded;
    }
};

class InformationDecoding {
public:
    string decode(string sentence, Morse morse) {
        string decoded = "";
        string letter = "";
        for (char& c : sentence) {
            if (c != ' ') {
                letter += c;
            }
            else {
                for (int i = 0; i < morse.morse.size(); i++) {
                    if (morse.morse[i] == letter) {
                        decoded += morse.letters[i];
                        break;
                    }
                }
                letter = "";
            }
        }
        return decoded;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Morse morse;
    InformationEncoding encoder;
    InformationDecoding decoder;

    string sentence = "ÀÁâ";
    string encoded = encoder.encode(sentence, morse);
    cout << encoded << endl;

    string decoded = decoder.decode(encoded, morse);
    cout << decoded << endl;

    return 0;
}
