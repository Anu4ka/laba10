#pragma once

class Cstring{
private:
    char* original;
    int originalsize;
public:
    Cstring();
    Cstring(char* original);
    Cstring(Cstring& other);
    Cstring& operator=(const Cstring& other);
    ~Cstring();
    void copypaste(int begin, int end, char* other);

    Cstring operator-(char* other);
    Cstring operator+(char* other);

    bool operator!=(Cstring& other);

    void Print();
};