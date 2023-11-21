#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

class Year {
    int year;
public:
    Year(int y) : year(y) {}
    int getYear() { return year; }
};

class Month {
    int month;
public:
    Month(int m) : month(m) {}
    int getMonth() { return month; }
};

class Day {
    int day;
public:
    Day(int d) : day(d) {}
    int getDay() { return day; }
};

class Hour {
    int hour;
public:
    Hour(int h) : hour(h) {}
    int getHour() { return hour; }
};

class Minute {
    int minute;
public:
    Minute(int min) : minute(min) {}
    int getMinute() { return minute; }
};

class Note {
    Year year;
    Month month;
    Day day;
    Hour hour;
    Minute minute;
    string note;
public:
    Note(Year y, Month m, Day d, Hour h, Minute min, const string& n)
        : year(y), month(m), day(d), hour(h), minute(min), note(n) {}
    void display() {
        cout << "Note: " << note << "\nDate: " << day.getDay() << "/" << month.getMonth() << "/" << year.getYear()
            << "\nTime: " << hour.getHour() << ":" << minute.getMinute() << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Note> notes;
    notes.emplace_back(Year(2023), Month(11), Day(14), Hour(18), Minute(59), "Перша нотатка.");
    notes.emplace_back(Year(2023), Month(11), Day(15), Hour(12), Minute(30), "Друга нотатка.");
    for (Note& note : notes) {
        note.display();
        cout << endl;
    }
    return 0;
}
