﻿
#include <iostream>
#include <string>

int main()
{
    int n;
    std::string S;
    do {
        std::cout << "Write number < 4000: "; std::cin >> n;
        std::cout << std::endl;
    } while ((n > 4000) || (n < 0))

        // M = 1000
        int k = n / 1000;
    if (k != 0) {

        for (int i = 0; i < k; i++) {
            S = S + "M";
        }
        n = n % 1000;
    }
    // C = 100
    k = n / 100;
    if (k != 0) {

        if (k == 5) {
            S = S + "D";
        }
        else {
            for (int i = 0; i < k; i++) {
                S = S + "C";
            }
        }
        n = n % 100;
    }
    // X = 10
    k = n / 10;
    if (k != 0) {

        if (k == 5) {
            S = S + "L";
        }
        else {
            for (int i = 0; i < k; i++) {
                S = S + "X";
            }
        }
        n = n % 10;
    }
    // I = 1
    k = n / 1;
    if (k != 0) {

        if (k == 5) {
            S = S + "V";
        }
        else {
            for (int i = 0; i < k; i++) {
                S = S + "I";
            }
        }
        n = n % 1;
    }

    std::cout << "Your number in the Roman numeral system: " << S << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;
}