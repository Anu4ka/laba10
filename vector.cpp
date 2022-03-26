#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <exception>

#include "vector.hpp"

using namespace std;

int Vector::getsize() const{
    return this->isize;
}

int& Vector::operator[](int index){
    if(index < 0 && index >= this->isize){
        throw runtime_error("Array index out of bounds!");
    }

    return array[index];
}


const int& Vector::operator[](int index) const {
    if(index < 0 || index >= this->isize){
        throw runtime_error("Array index out of bounds!");
    }
    return array[index];
}

istream& operator >> (istream &str, Vector& prototipe){
    str >> prototipe;
    return str;
}

ostream& operator << (ostream &str, const Vector& prototipe){
    return str << prototipe;
}

Vector& Vector::operator++ (int index){
    if(index < 0 && index >= this->isize){
        throw runtime_error("Array index out of bounds!");
    }
    this->array[index]++;
    return *this;
}

void Vector::fillrandomly(){
    for(int i = 0; i < this->isize; i++){
        array[i] = rand() % 100;
    }
}

void printeq2(Vector& vector){
    for(int i = 0; i < vector.isize; i++){
        if(vector.array[i] == 2){
            cout << i << " ";
        }
    }
}

Vector::Vector(const Vector& other){
    this->isize = other.isize;
    this->array = new int[other.isize];
    for(int i = 0; i < other.isize; i++){
        this->array[i] = other.array[i];
    }
}

Vector::Vector(){
    this->isize = 13;
    this->array = new int[isize];
    for(int i = 0; i < this->isize; i++){
        array[i] = 0;
    }
}

Vector::Vector(int isize){
    this->isize = isize;
    this->array = new int[isize];
    for(int i = 0; i < this->isize; i++){
        array[i] = 0;
    }
}

Vector::~Vector() {
    delete[] this->array;
}

void Vector::print() const{
    for(int i = 0; i < isize; i++){
        printf("%10d", array[i]);
    }
}

Vector& Vector::operator = (const Vector& other){
    if(this->array){
        delete this->array;
    }

    this->isize = other.isize;
    this->array = new int[this->isize];
    for(int i = 0; i < isize; i++){
        this->array[i] = other.array[i];
    }

    return *this;
}

Vector Vector::operator + (Vector& other){
    Vector temp(this->isize);
    for(int i = 0; i < isize; i++){
        temp.array[i] = this->array[i] + other.array[i];
    }
    return temp;
}

void Vector::changeCapacity(int capacity){
    Vector temp(*this);
    if(this->array){
        delete this->array;
    }
    this->isize = capacity;
    this->array = new int[this->isize];
    for(int i = 0; i < this->isize; i++){
        if(i < temp.isize){
            array[i] = temp[i];
        } else {
            array[i] = 0;
        }
    }
}