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
    void edit(const string& new_note) {
        note = new_note;
    }
};

void displayAllNotes(vector<Note>& notes) {
    cout << "\nAll notes:\n";
    for (int i = 0; i < notes.size(); i++) {
        cout << "Note " << i + 1 << ":\n";
        notes[i].display();
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Note> notes;
    notes.emplace_back(Year(2023), Month(11), Day(14), Hour(18), Minute(59), "First note.");
    notes.emplace_back(Year(2023), Month(11), Day(15), Hour(12), Minute(30), "Second note.");

    while (true) {
        cout << "Choose an action:\n1. Add a note\n2. Delete a note\n3. Edit a note\n4. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int y, m, d, h, min;
            string n;
            cout << "Enter year: ";
            cin >> y;
            cout << "Enter month: ";
            cin >> m;
            cout << "Enter day: ";
            cin >> d;
            cout << "Enter hour: ";
            cin >> h;
            cout << "Enter minute: ";
            cin >> min;
            cout << "Enter note: ";
            cin.ignore();
            getline(cin, n);
            notes.emplace_back(Year(y), Month(m), Day(d), Hour(h), Minute(min), n);
        }
        else if (choice == 2) {
            int index;
            cout << "Enter the index of the note to delete: ";
            cin >> index;
            if (index < 0 || index >= notes.size()) {
                cout << "Invalid index!\n";
            }
            else {
                notes.erase(notes.begin() + index);
            }
        }
        else if (choice == 3) {
            int index;
            string new_note;
            cout << "Enter the index of the note to edit: ";
            cin >> index;
            if (index < 0 || index >= notes.size()) {
                cout << "Invalid index!\n";
            }
            else {
                cout << "Enter new note: ";
                cin.ignore();
                getline(cin, new_note);
                notes[index].edit(new_note);
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Unknown action!\n";
        }
        displayAllNotes(notes);
    }

    return 0;
}
