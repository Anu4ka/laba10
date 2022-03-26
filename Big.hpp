#pragma once

#include <cstring>
#include <string.h>

using namespace std;

class Big{
private:
    int digit;
    unsigned int* value;
public:
    static unsigned int sistem;

    Big();
    Big(string number);
    Big(const Big& other);
    Big operator =(const Big& other);

    ~Big();

    Big operator*(const int& other);
    Big operator+(const int& other);
    unsigned int& operator[](int index);

    void PrintHex() const;
    void PrintInt() const;
};