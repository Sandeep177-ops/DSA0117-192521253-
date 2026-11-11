#include <iostream>
using namespace std;

enum Zone { INNER, MIDDLE, OUTER, AIRPORT };

class MonthlyPass {
public:
    bool inner;
    bool middle;

    MonthlyPass(bool a, bool b) {
        inner = a;
        middle = b;
    }

    bool covers(Zone z) {
        if (z == INNER && inner) {
            return true;
        }
        if (z == MIDDLE && middle) {
            return true;
        }
        return false;
    }
};

class SmartCard {
private:
    int balance;

public:
    SmartCard(int b) {
        balance = b;
    }

    void pay(int fare) {
        if (balance - fare >= 5000) {
            balance = balance - fare;
            cout << "Payment successful\n";
        } else {
            cout << "Payment denied\n";
        }
    }

    void showBalance() {
        cout << "Balance: " << balance << " paise\n";
    }
};

int calculateFare(Zone z, int hour, bool weekend, MonthlyPass pass) {
    if (pass.covers(z)) {
        return 0;
    }

    int fare;

    if (z == INNER) {
        fare = 1000;
    } else if (z == MIDDLE) {
        fare = 2000;
    } else if (z == OUTER) {
        fare = 3000;
    } else {
        fare = 6000;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (weekend == true) {
        fare = fare - fare * 10 / 100;
    } else if (peak == true) {
        fare = fare + fare * 20 / 100;
    }

    return fare;
}

int main() {
    MonthlyPass pass(true, true); // Covers Inner and Middle
    SmartCard card(20000);

    int fare1 = calculateFare(AIRPORT, 18, false, pass);
    cout << "Airport peak fare: " << fare1 << " paise\n";
    card.pay(fare1);

    int fare2 = calculateFare(INNER, 18, true, pass);
    cout << "Inner fare with pass: " << fare2 << " paise\n";
    card.pay(fare2);

    card.showBalance();

    return 0;
}