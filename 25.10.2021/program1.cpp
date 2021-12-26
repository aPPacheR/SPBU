#include <iostream>

using namespace std;

int main() {
    int day, month, year;

    do {
        cout << "Input day: ";
        cin >> day;
    } while (day < 1 or day > 31);

    do {
        cout << "Input month: ";
        cin >> month;
    } while (month < 1 or month > 12);

    cout << "Input year: ";
    cin >> year;

    int a = (14 - month) / 12;
    int m = month + 12 * a - 2;
    int d = 0;
    int y;

    while (d != 5) {
        ++year;
        y = year - a;
        d = (day + y + y / 4 + y / 400 - y / 100 + 31 * m / 12) % 7;
    }
    cout << year;

    return 0;
}
