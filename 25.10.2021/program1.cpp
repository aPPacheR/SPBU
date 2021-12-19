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
    int y = year - a + 1;
    int m = month + 12 * a - 2;
    int d = 0;

    while (1) {
        d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
        if (d == 5) break;
        y += 1;
    }

    cout << y;

    return 0;
}