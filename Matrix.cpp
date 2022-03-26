#include <iostream>
#include <cmath>
#include <cstring>
#include <string.h>
#include <iomanip>

#include "vector.hpp"
#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(){
    counter++;
    name = "Matrix#" + to_string(counter);
    size_of_matrix = 0;
    matrix = new Vector[size_of_matrix];
    for(int i = 0; i < size_of_matrix; i++){
        Vector temp(size_of_matrix);
        matrix[i] = temp;
        matrix[i][i] = 1;
    }
}

Matrix::Matrix(int size_of_matrix){
    counter++;
    name = "Matrix#" + to_string(counter);
    this->size_of_matrix = size_of_matrix;
    matrix = new Vector[size_of_matrix];
    for(int i = 0; i < size_of_matrix; i++){
        Vector temp(size_of_matrix);
        matrix[i] = temp;
        matrix[i][i] = 1;
    }
}

Matrix::Matrix(const Matrix& other){
    counter++;
    name = "Matrix#" + to_string(counter);
    this->size_of_matrix = other.size_of_matrix;
    this->matrix = new Vector[this->size_of_matrix];
    for(int i = 0; i < this->size_of_matrix; i++){
        this->matrix[i] = other.matrix[i];
    }
}

void Matrix::Print(){
    cout << setw(int(size_of_matrix * 5 + size_of_matrix)) << name << endl;
    for(int i = 0; i < size_of_matrix; i++){
        matrix[i].print();
        cout << endl;
    }
    cout << "\n";
}

Vector& Matrix::operator[](int index){
    if(index < 0 || index >= size_of_matrix){
        throw runtime_error("Matrix index out of bounds!");
    }
    return matrix[index];
}

Matrix::~Matrix(){
    for(int i = 0; i < size_of_matrix; i++){
        matrix[i].~Vector();
    }
}

Matrix& Matrix::operator = (const Matrix& other) {
    this->size_of_matrix = other.size_of_matrix;
    if (this->matrix) {
        this->~Matrix();
    }
    this->matrix = new Vector[other.size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++) {
        this->matrix[i] = other.matrix[i];
    }
    return *this;
}

Matrix Matrix::operator + (Matrix& other){
    Matrix temp(this->size_of_matrix);
    for(int i = 0; i < size_of_matrix; i++){
        temp.matrix[i] = this->matrix[i] + other.matrix[i];
    }
    return temp;
}

Matrix Matrix::operator*(Matrix& other){
    Matrix tempmatrix(other.size_of_matrix);
    for(int i = 0; i < size_of_matrix; i++){
        for(int i_n = 0; i_n < size_of_matrix; i_n++){
            int sum = 0;
            for(int counter = 0; counter < size_of_matrix; counter++){
                sum += matrix[i][counter] * other.matrix[counter][i_n];
            }
            tempmatrix[i][i_n] = sum;
        }
    }
    tempmatrix;
    return tempmatrix;
}

Matrix power(Matrix& matrix, int power){
    Matrix temp(matrix.size_of_matrix);
    temp = matrix;
    if(power == 1){
        return temp;
    }
    if(power == 0){
        Matrix E(matrix.size_of_matrix);
        return E;
    }
    for(int i = 1; i < power; i++){
        temp = temp * matrix;
    }
    return temp;
}

void Matrix::fillrandomly(){
    for(int i = 0; i < size_of_matrix; i++){
        matrix[i].fillrandomly();
    }
}

Matrix work(Matrix& matrix, int ipower){
    Matrix temp(matrix.size_of_matrix);
    Matrix coppy(matrix.size_of_matrix);
    for(int i = 1; i <= ipower; i++){
        coppy = power(matrix, i);
        temp = temp + coppy;
    }
    return temp;
}

void Matrix::changeCopasity(int icopasity){
    Matrix temp(*this);
    this->size_of_matrix = icopasity;
    this->~Matrix();
    this->matrix = new Vector[icopasity];
    Matrix zero(icopasity);
    for(int i = 0; i < this->size_of_matrix; i++){
        if(i < temp.size_of_matrix){
            temp[i].changeCapacity(icopasity);
            matrix[i] = temp[i];
        } else {
            temp[i].changeCapacity(icopasity);
            matrix[i] = zero[i];
        }
    }
}