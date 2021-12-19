
#include <iostream>

int main()
{
    double x, S{};
    int n;
    std::cout << "Write x: "; std::cin >> x;
    do {
        std::cout << "Write n: "; std::cin >> n;
    } while (n < 0);

    S = sin(x);

    for (int i = 1; i < n; i++) {
        S = S + sin(S);
    }
    std::cout << std::endl;

    std::cout << "S = " << S << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;


}
