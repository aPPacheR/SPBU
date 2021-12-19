#include <iostream>

int main()
{
    unsigned int n;
    unsigned int m;

    do {
        std::cout << "Input positive integer n: ";
        std::cin >> n;
        std::cout << "Input positive integer m: ";
        std::cin >> m;
    } while (n <= 0 || m <= 0);

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {

            for (int k = 0; k < n - 1 - i; ++k) std::cout << " ";

            for (int k = 0; k < 1 + 2 * i; ++k) std::cout << "*";

            for (int k = 0; k < n - 1 - i; ++k) std::cout << " ";

        }
        std::cout << std::endl;
    }

    for (int i = n - 2; i >= 0; --i) {

        for (int j = 0; j < m; ++j) {

            for (int k = 0; k < n - 1 - i; ++k) std::cout << " ";

            for (int k = 0; k < 1 + 2 * i; ++k) std::cout << "*";

            for (int k = 0; k < n - 1 - i; ++k) std::cout << " ";

        }
        std::cout << std::endl;
    }

    return 0;
}