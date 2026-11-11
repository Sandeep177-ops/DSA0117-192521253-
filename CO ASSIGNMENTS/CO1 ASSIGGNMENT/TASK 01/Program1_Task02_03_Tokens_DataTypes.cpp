#include <iostream>
using namespace std;

int main() {
    const int INNER_FARE = 1000;
    const int MIDDLE_FARE = 2000;
    const int OUTER_FARE = 3000;
    int balance = 10000;
    int zone = 1;
    bool peak = true;
    char passenger = 'S';

    cout << "Inner fare: " << INNER_FARE << " paise\n";
    cout << "Middle fare: " << MIDDLE_FARE << " paise\n";
    cout << "Outer fare: " << OUTER_FARE << " paise\n";
    cout << "Balance: " << balance << " paise\n";
    cout << "Zone: " << zone << '\n';
    cout << "Peak: " << peak << '\n';
    cout << "Passenger type: " << passenger << '\n';

    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " byte\n";
    cout << "Size of bool: " << sizeof(bool) << " byte\n";
    return 0;
}