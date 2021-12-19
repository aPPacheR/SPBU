
#include <iostream>

int main()
{
    int n, k = 0;
    std::cout << "Write n: "; std::cin >> n;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
            k = k + 1;
        }
        else {
            n = n * 3 + 1;
            k = k + 1;
        }
    }


    std::cout << std::endl;

    std::cout << "Number of steps - " << k << std::endl;
    std::cout << "Final number - " << n << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;
}
