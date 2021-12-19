#include <iostream>

using namespace std;

int main() {
    int N, roomsonfloor = 1, temp = 0, Floor = 1;
    cin >> N;

    while (N > 0) {
        if (temp == roomsonfloor) {
            temp = 0;
            roomsonfloor++;
        }
        else if (N > roomsonfloor) {
            temp++;
            Floor++;
            N -= roomsonfloor;
        }
        else {
            break;
        }

    }

    cout << Floor << " " << N;


    return 0;
}