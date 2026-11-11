#include <iostream>
#include <climits>
using namespace std;

int main() {
    int fare = 3000; // Rs 30 in paise
    long long total;

    total = 20000LL * fare;
    cout << "20000 journeys: " << total << " paise\n";

    total = 500000LL * fare;
    cout << "500000 journeys: " << total << " paise\n";

    total = 3000000LL * fare;
    cout << "3000000 journeys: " << total << " paise\n";

    cout << "Maximum int: " << INT_MAX << '\n';
    cout << "Maximum long long: " << LLONG_MAX << '\n';

    return 0;
}