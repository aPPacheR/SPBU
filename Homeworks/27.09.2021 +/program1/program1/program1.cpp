
#include <iostream>

int main()
{
    for (int a = 32; a <= 255; ++a) {
        std::cout << char(a) << " - " << a << std::endl;
        
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}

