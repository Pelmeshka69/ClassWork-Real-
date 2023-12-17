
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> lines;
    string line;

    cout << "Enter lines of text (enter 'end' to stop):" << endl;
    while (getline(cin, line) && line != "end") {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end(),  {
        return a.size() < b.size();
    });

    cout << "Sorted lines:" << endl;
    for (const string &sorted_line : lines) {
        cout << sorted_line << endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> even_numbers;
    copy_if(numbers.begin(), numbers.end(), back_inserter(even_numbers), { return x % 2 == 0; });
    for(int n : even_numbers) {
        cout << n << " ";
    }
    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    auto add =  { return a + b; };
    auto subtract =  { return a - b; };
    auto multiply =  { return a * b; };
    auto divide =  { return a / b; };

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second number: ";
    cin >> num2;

    switch(operation) {
        case '+':
            cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << multiply(num1, num2) << endl;
            break;
        case '/':
            if(num2 != 0)
                cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << divide(num1, num2) << endl;
            else
                cout << "Error: Division by zero is not possible." << endl;
            break;
        default:
            cout << "Error: Unknown operation." << endl;
    }

    return 0;
}
*/
