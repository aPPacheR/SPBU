#include <fstream>
#include <iostream>
#include <string>

std::string Hex(int a) {

    std::string result;
    int b = a % 16;
    a /= 16;

    if (a <= 9) {
        result += a + '0';
    }
    else {
        result += a + 'F' - 15;
    }

    if (b <= 9) {
        result += b + '0';
    }
    else {
        result += b + 'F' - 15;
    }

    return result;
}

std::string number(int k) {

    std::string result = "0";

    for (int i = 0; i < 4; ++i) {

        result = Hex(k % 256) + result;
        k /= 256;
    }

    return ("0" + result);
}

int main()
{
    const char* ifname = "input.txt";
    const char* ofname = "output.txt";

    std::ifstream inFile(ifname, std::ios_base::binary);
    if (!inFile)
    {
        std::cout << "Can not open file to read: " << ifname << std::endl;
        return 1;
    }

    std::ofstream outFile(ofname);
    if (!outFile)
    {
        std::cout << "Can not open file to write: " << ofname << std::endl;
        inFile.close();
        return 2;
    }
    unsigned char ch;
    int count = 0, count_str = 0;
    std::string s = "";
    while (inFile.peek() != EOF) {
        if (!count) outFile << number(count_str) << ": ";
        ch = inFile.get();
        ++count;
        if (ch < 32) s += '.';
        else s += ch;
        outFile << Hex(ch) << " ";
        if (count == 8) {
            outFile << "| ";
        }
        if (count == 16) {
            outFile << " " << s << std::endl;
            count = 0;
            s = "";
            ++count_str;
        }

    }
    if (count != 0 && count < 8)
    {
        for (int i = 0; i < 8 - count; ++i)
        {
            outFile << "   ";
        }
        outFile << "| ";
        for (int i = 0; i < 8; ++i)
        {
            outFile << "   ";
        }
        outFile << " " << s;
    }
    else if (count)
    {
        for (int i = 0; i < 16 - count; ++i)
        {
            outFile << "   ";
        }
        outFile << " " << s;
    }


    std::cout << "Done!" << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}
