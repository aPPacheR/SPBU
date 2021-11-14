
#include <iostream>

int Akk(int m, int n) {
    if (m == 0)
        return (n + 1);

    else if ((m > 0) && (n == 0))
        return Akk(m - 1, 1);

    else if ((m > 0) && (n > 0))
        return Akk(m - 1, Akk(m, n - 1));

    else
        return 0;
}

int main()
{
    int m = 0, n = 0;

    do {
        std::cout << "Write positive number m: "; std::cin >> m;
    } while (m < 0);

    do {
        std::cout << "Write positive numbers n: "; std::cin >> n;
    } while (n < 0);

    std::cout << std::endl;

    std::cout << "Akk = " << Akk(m, n) << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;
}