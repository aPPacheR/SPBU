#include <iostream>

using namespace std;

void dig(int m, int gen, int num);

int main() {

    setlocale(LC_ALL, "Russian");
    int numb = 0;
    int n;
    do {
        cout << "Input positive integer: ";
        cin >> n;
    } while (n < 1 or n > 1000000000);

    //миллиарды

    if (n == 1000000000) cout << "один миллиард";

    //миллионы

    int mil = n % 1000000000 / 1000000;

    if (mil > 0) {
        numb++;
        dig(mil, 0, numb);
        if ((mil % 100) < 11 or (mil % 100) > 19) {
            switch (mil % 10) {
            case 4: cout << " миллиона"; break;
            case 3: cout << " миллиона"; break;
            case 2: cout << " миллиона"; break;
            case 1: cout << " миллион"; break;
            default: cout << " миллионов";
            }
        }
        else cout << " миллионов";
    }

    //тысячи

    int th = n % 1000000 / 1000;

    if (th > 0) {
        numb++;
        dig(th, 1, numb);
        if ((th % 100) < 11 or (th % 100) > 19) {
            switch (th % 10) {
            case 4: cout << " тясячи"; break;
            case 3: cout << " тысячи"; break;
            case 2: cout << " тысячи"; break;
            case 1: cout << " тысяча"; break;
            default: cout << " тысяч";
            }
        }
        else cout << " тысяч";
    }

    //единицы

    int ed = n % 1000;
    numb++;
    dig(ed, 0, numb);

    return 0;
}

void dig(int m, int gen, int num) {
    if (num != 1 and m / 100 != 0) {
        cout << " ";
        num++;
    }
    if (m / 100 != 0) {
        num++;
    }
    switch (m / 100) {
    case 9: cout << "девятьсот"; break;
    case 8: cout << "восемьсот"; break;
    case 7: cout << "семьсот"; break;
    case 6: cout << "шестьсот"; break;
    case 5: cout << "пятьсот"; break;
    case 4: cout << "четыреста"; break;
    case 3: cout << "триста"; break;
    case 2: cout << "двести"; break;
    case 1: cout << "сто"; break;
    }

    if (num != 1 and m / 10 % 10 != 0 and (m % 100 < 11 or m % 100 > 19)) {
        cout << " ";
        num++;
    }
    if (m / 10 % 10 != 0 and (m % 100 < 11 or m % 100 > 19)) {
        num++;
    }
    switch (m / 10 % 10) {
    case 9: cout << "девяносто"; break;
    case 8: cout << "восемьдесят"; break;
    case 7: cout << "семьдесят"; break;
    case 6: cout << "шестьдесят"; break;
    case 5: cout << "пятьдесят"; break;
    case 4: cout << "сорок"; break;
    case 3: cout << "тридцать"; break;
    case 2: cout << "двадцать"; break;
    }

    if (num != 1 and m % 10 != 0) {
        cout << " ";
        num++;
    }
    if (m % 10 != 0) {
        num++;
    }

    if (m % 100 > 10 and m % 100 < 20) {
        switch (m % 100) {
        case 19: cout << "девятнадцать"; break;
        case 18: cout << "восемнадцать"; break;
        case 17: cout << "семнадцать"; break;
        case 16: cout << "шестнадцать"; break;
        case 15: cout << "пятнадцать"; break;
        case 14: cout << "четырнадцать"; break;
        case 13: cout << "тринадцать"; break;
        case 12: cout << "двенадцать"; break;
        case 11: cout << "одиннадцать"; break;
        }

    }
    else {
        switch (m % 10) {
        case 9: cout << "девять"; break;
        case 8: cout << "восемь"; break;
        case 7: cout << "семь"; break;
        case 6: cout << "шесть"; break;
        case 5: cout << "пять"; break;
        case 4: cout << "четыре"; break;
        case 3: cout << "три"; break;
        case 2: cout << "два"; break;
        }

        if (m % 10 == 1) {
            if (gen == 0) cout << "один";
            if (gen == 1) cout << "одна";
        }
    }


}