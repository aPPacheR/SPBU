#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int d, a, m, y;

    for (int i = 1901; i < 2001; ++i) {
        for (int j = 1; j < 13; ++j) {
            a = (14 - j) / 12;
            y = i - a;
            m = j + 12 * a - 2;

            d = (13 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
            if (d == 5) {
                ++count;
            }
        }
    }

    cout << "Count of 13th fridays in 20th century: " << count << endl;
    cout << "Possibility of 13th fridays: " << double(count) / 12 / 100 << endl;

    return 0;
}