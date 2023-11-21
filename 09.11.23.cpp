#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>

using namespace std;

class AlphabetSorter {
public:
    static bool sort(const string& a, const string& b) {
        string lowerA = a;
        transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);

        string lowerB = b;
        transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);

        return lowerA < lowerB;
    }
};

class LengthSorter {
public:
    static bool sort(const string& a, const string& b) {
        return a.length() < b.length();
    }
};

class NumericSorter {
public:
    static bool isNumeric(const string& str) {
        for (char ch : str) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        return true;
    }

    static int convertToNumber(const string& str) {
        int result = 0;
        for (char ch : str) {
            if (isdigit(ch)) {
                result = result * 10 + (ch - '0');
            }
        }
        return result;
    }

    static bool sort(const string& a, const string& b) {
        if (isNumeric(a) && isNumeric(b)) {
            return convertToNumber(a) < convertToNumber(b);
        }
        return isNumeric(a);
    }
};

class UppercaseSorter {
public:
    static bool sort(const string& a, const string& b) {
        string upperA = a;
        transform(upperA.begin(), upperA.end(), upperA.begin(), ::toupper);

        string upperB = b;
        transform(upperB.begin(), upperB.end(), upperB.begin(), ::toupper);

        return upperA < upperB;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<string> words = { "Hello", "A", "123abc", "a", "B", "" };

    sort(words.begin(), words.end(), AlphabetSorter::sort);

    cout << "Сортування по алфавіту:\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    sort(words.begin(), words.end(), LengthSorter::sort);

    cout << "Сортування за довжиною:\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    sort(words.begin(), words.end(), NumericSorter::sort);

    cout << "Сортування чисел:\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    reverse(words.begin(), words.end());

    cout << "Інверсія:\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    int emptyCount = 0;
    for (const auto& word : words) {
        if (word.empty()) {
            emptyCount++;
        }
    }
    cout << "Порожні елементи: " << emptyCount << "\n\n";

    sort(words.begin(), words.end(), UppercaseSorter::sort);

    cout << "Сортування з великих літер:\n";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << "\n\n";

    return 0;
}
