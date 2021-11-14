#include <iostream>
#include <string>

std::string S;

void F(int n, int m) {
    int k = 0;
    while(n > 0) {
        k = n % m;
        if (k <= 9) {
            S = char(k + '0') + S;
        }
        else {
            S = char(k - 10 + 'A') + S;
        }
        n = n / m;
    }
    std::cout << S;
}

int main()
{
    int n, m;
    std::cout << "Write a number: "; std::cin >> n;
    std::cout << "Write the number system: "; std::cin >> m;
    
    std::cout << std::endl;

    std::cout << "Your answer: "; F(n, m);

    std::cout << std::endl;
   
    std::cout << std::endl;
    system("pause");
    return 0;

    
}