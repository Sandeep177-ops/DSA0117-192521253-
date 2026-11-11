#include <iostream>
#include <iomanip>
using namespace std;

enum Zone { INNER, MIDDLE, OUTER };

int fare(Zone z, bool peak) {
    int amount;

    switch (z) {
        case INNER:
            amount = 1000;
            break;
        case MIDDLE:
            amount = 2000;
            break;
        case OUTER:
            amount = 3000;
            break;
        default:
            return -1;
    }

    if (peak == true) {
        amount = amount + amount * 20 / 100;
    }

    return amount;
}

bool canTravel(int balance, int f) {
    if (f < 0) {
        return false;
    }
    if (balance - f >= 5000) {
        return true;
    }
    return false;
}

int main() {
    int balance = 10000;

    Zone trips[3] = {INNER, OUTER, MIDDLE};
    bool peak[3] = {false, true, false};

    for (int i = 0; i < 3; i++) {
        int f = fare(trips[i], peak[i]);

        if (canTravel(balance, f)) {
            balance = balance - f;
            cout << "Fare Rs " << f / 100 << '.'
                 << setw(2) << setfill('0') << f % 100
                 << setfill(' ');
        } else {
            cout << "Denied (low balance)";
        }

        cout << " balance Rs " << balance / 100 << '\n';
    }

    return 0;
}