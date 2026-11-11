#include <iostream>
using namespace std;

// Procedural method
bool canPay(int balance, int fare) {
    if (balance - fare >= 5000) {
        return true;
    }
    return false;
}

// Object-oriented method
class SmartCard {
private:
    int balance;

public:
    SmartCard(int b) {
        balance = b;
    }

    bool canTravel(int fare) {
        return balance - fare >= 5000;
    }

    void deduct(int fare) {
        if (canTravel(fare)) {
            balance = balance - fare;
        }
    }

    void display() {
        cout << "OOP balance: " << balance << " paise\n";
    }
};

int main() {
    int balance = 10000;
    int fare = 2000;

    if (canPay(balance, fare)) {
        balance = balance - fare;
    }
    cout << "Procedural balance: " << balance << " paise\n";

    SmartCard card(10000);
    card.deduct(2000);
    card.display();

    return 0;
}