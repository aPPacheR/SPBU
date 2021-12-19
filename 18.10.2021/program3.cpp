#include <iostream>
#include <string>

int main()
{
    int n;
    std::string s;
    do {
        std::cout << "Write number < 4000: "; std::cin >> n;
        std::cout << std::endl;
    } while ((n > 4000) || (n < 0));

        // M = 1000
	int k = n / 1000;
    if (k != 0) {

        for (int i = 0; i < k; i++) {
            s = s + "M";
        }
        n = n % 1000;
    }
    // C = 100
    k = n / 100;
    if (k != 0) {

        if (k == 5) {
            s = s + "D";
        }
        else {
            for (int i = 0; i < k; i++) {
                s = s + "C";
            }
        }
        n = n % 100;
    }
    // X = 10
    k = n / 10;
    if (k != 0) {
        switch (k % 10){
        case 1: s = s + "X"; break;
        case 2: s = s + "XI"; break;
        case 3: s = s + "XII"; break;
        case 4: s = s + "XL"; break;
        case 5: s = s + "L"; break;
        case 6: s = s + "LX"; break;
        case 7: s = s + "LXX"; break;
        case 8: s = s + "LXXX"; break;
        case 9: s = s + "XC"; break;
        }
    }
    k = n / 1;
    if (k != 0) {
	    switch (k % 10){
	    case 1: s = s + "I"; break;
	    case 2: s = s + "II"; break;
	    case 3: s = s + "III"; break;
	    case 4: s = s + "IV"; break;
	    case 5: s = s + "V"; break;
	    case 6: s = s + "VI"; break;
	    case 7: s = s + "VII"; break;
	    case 8: s = s + "VIII"; break;
	    case 9: s = s + "IX"; break;
	    }

        }
    std::cout << "Your number in the Roman numeral system: " << s << std::endl;

    std::cout << std::endl;
   
    return 0;
}

