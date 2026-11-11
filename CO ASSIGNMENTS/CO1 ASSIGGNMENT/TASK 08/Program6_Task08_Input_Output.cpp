#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int hour;

    cout << "Enter hour (0 to 23): ";
    cin >> hour;

    while (cin.fail() || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> hour;
    }

    int balance;
    cout << "Enter balance in paise: ";
    cin >> balance;

    while (cin.fail() || balance < 0) {
        cout << "Invalid balance. Enter again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> balance;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    cout << boolalpha << "Peak hour: " << peak << '\n';
    cout << "Balance: Rs " << balance / 100 << '.'
         << setw(2) << setfill('0') << balance % 100 << '\n';

    return 0;
}