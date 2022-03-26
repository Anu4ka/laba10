#pragma once
#include "vector.hpp"
#include <cstring>
#include <string.h>

using namespace std;


class Matrix{
private:
    Vector* matrix;
    int size_of_matrix;
    string name;
public:
    static int counter;
    Matrix();
    Matrix(int size_of_matrix);
    Matrix(const Matrix& matrix);
    void Print();
    Vector& operator[](int index);
    ~Matrix();
    Matrix& operator =(const Matrix& other);
    Matrix operator + (Matrix& other);
    Matrix operator * (Matrix& other);
    friend Matrix power(Matrix& matrix, int power);
    void fillrandomly();
    friend Matrix work(Matrix& matrix, int ipower);
    void changeCopasity(int icopasity);
};

