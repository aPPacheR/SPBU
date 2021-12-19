#include <iostream>
#include <string.h>

bool palindrom(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}

int main()
{
    char s[100];
        std::cout << "Wtite string: "; std::cin.getline(s, 100);

        if (palindrom(s))
            std::cout << s << " it is polindrom" << std::endl;
        else
            std::cout << s << "it isn't polindrom" << std::endl;

        std::cout << std::endl;
    std::cout << std::endl;
    system("pause");
    return 0;
}
