#include <iostream>
using namespace std;

int getFare(int zone, int hour) {
    int fare;

    if (zone == 1) {
        fare = 1000;
    } else if (zone == 2) {
        fare = 2000;
    } else if (zone == 3) {
        fare = 3000;
    } else {
        return -1;
    }

    if (hour < 0 || hour > 23) {
        return -1;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20)) {
        fare = fare + fare * 20 / 100;
    }

    return fare;
}

int main() {
    int zone, hour, balance;

    cout << "Enter zone (1-3), hour and balance in paise: ";
    cin >> zone >> hour >> balance;

    if (cin.fail() || balance < 0) {
        cout << "Invalid input\n";
        return 0;
    }

    int f = getFare(zone, hour);

    if (f == -1) {
        cout << "Invalid zone or hour\n";
    } else if (balance - f < 5000) {
        cout << "Journey denied. Rs 50 must remain.\n";
    } else {
        balance = balance - f;
        cout << "Fare: " << f << " paise\n";
        cout << "Remaining balance: " << balance << " paise\n";
    }

    return 0;
}