#pragma once
#include <iostream>
#include <string>

class BigInteger {
    int value_[256];
    int size_;
    bool sign_;
public:
    BigInteger(); // конструктор умолчания (число равно нулю) DONE!
    BigInteger(int); // конструктор преобразования из обычного целого числа DONE!
    BigInteger(const std::string&); // конструктор преобразования из строки DONE! //TODO

    void reverse();
    void deleteZero();

    BigInteger(const BigInteger&); // конструктор копирования DONE!

    // унарные плюс и минус
    BigInteger operator+() const; //DONE
    BigInteger operator-() const; //DONE


    // операции сравнения
    bool operator==(const BigInteger& X);  //DONE
    bool operator!=(const BigInteger&);//DONE

    bool operator<(const BigInteger&); //DONE
    bool operator>(const BigInteger&); //DONE
    bool operator<=(const BigInteger&);//DONE
    bool operator>=(const BigInteger&);//DONE

    // операция присваивания 
    BigInteger& operator=(const BigInteger&); //DONE
    BigInteger& operator=(BigInteger&& ); //DONE


    // арифметические операции
    BigInteger operator+(const BigInteger&) const; //DONE
    BigInteger operator-(const BigInteger&) const; //DONE
    BigInteger operator*(const BigInteger&) const; //DONE
    BigInteger operator/(const BigInteger&) const;
    BigInteger operator%(const BigInteger&) const;


    // краткая форма операций
    BigInteger& operator+=(const BigInteger&); //DONE
    BigInteger& operator-=(const BigInteger&); //DONE
    BigInteger& operator*=(const BigInteger&); //DONE
    BigInteger& operator/=(const BigInteger&);
    BigInteger& operator%=(const BigInteger&);


    //TODO
    // префиксная форма
    BigInteger& operator++(); // ++v //DONE
    BigInteger& operator--(); // --v //DONE

    // постфиксная форма
    BigInteger operator++(int); // v++ //DONE
    BigInteger operator--(int); // v-- //DONE


    friend std::ostream& operator<<(std::ostream&, const BigInteger&); // вывод числа в выходной поток DONE!  //TODO
    friend std::istream& operator>>(std::istream&, BigInteger& ); // ввод числа из входного потока
};



