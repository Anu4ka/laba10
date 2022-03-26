#pragma once

#include <iostream>

class Vector {
private:
    int isize;
    int* array;
public:
    Vector();
    Vector(int isize);
    Vector(const Vector& other);
    ~Vector();

    Vector& operator = (const Vector &other);

    int getsize() const;
    void print() const;

    void fillrandomly();

    int& operator[](int index);
    const int& operator[](int index) const;

    Vector& operator++ (int index);

    friend std::istream& operator >> (std::istream &str, Vector& prototipe);
    friend std::ostream& operator << (std::ostream &str, const Vector& prototipe);
  
    Vector operator + (Vector& other);

    void changeCapacity(int capacity);

    friend void printeq2(Vector& vector);
};

