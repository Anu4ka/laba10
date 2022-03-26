#include <iostream>
#include <cstring>
#include <string.h>
#include <math.h>

#include "Big.hpp"

using namespace std;

Big::Big(){
    digit = 1;
    value = new unsigned int[digit];
    value[0] = 0;
}

int takeHex(string number);

Big::Big(string number){
    int num = takeHex(number);
    digit = 1;
    value = new unsigned int[digit];
    value[0] = num;
}

Big::~Big(){
    if(this->value != nullptr){
        delete[] this->value;
    }
}

Big::Big(const Big& other){
    this->digit = other.digit;
    this->value = new unsigned int[this->digit];
    for(int i = 0; i < other.digit; i++){
        this->value[i] = other.value[i];
    }
}

Big Big::operator*(const int& other){
    Big back(*this);
    int remember = 0;
    for(int i = 0; i < digit; i++){
        unsigned long long int temp = this->value[i];
        temp *= other;
        if(temp > sistem){
            if(i == digit - 1){
                Big temper(back);
                delete[] back.value;
                back.digit = temper.digit + 1;
                back.value = new unsigned int[temper.digit + 1];
                for(int i_n = 0; i_n < temper.digit; i_n++){
                    back.value[i_n] = temper.value[i_n];
                }
                back.value[this->digit] = 0;
                back.value[i] = temp % sistem;
                back.value[i + 1] = temp / sistem;
            } else {
                back.value[i] = (temp % sistem) + remember;
                remember = temp / sistem;
            }
        } else {
            back.value[i] = temp + remember;
            remember = 0;
        }
    }
    return back;
}

unsigned int& Big::operator[](int index){
    return this->value[index];
}

Big Big::operator+(const int& other){
    Big back(*this);
    int remember = 0;
    for(int i = 0; i < digit; i++){
        unsigned long long int temp = this->value[i];
        temp += other;
        if(temp > sistem){
            if(i == digit - 1){
                Big temper(back);
                delete[] back.value;
                back.digit = temper.digit + 1;
                back.value = new unsigned int[temper.digit + 1];
                for(int i_n = 0; i_n < temper.digit; i_n++){
                    back.value[i_n] = temper.value[i_n];
                }
                back.value[this->digit] = 0;
                back.value[i] = temp % sistem;
                back.value[i + 1] = temp / sistem;
            } else {
                back.value[i] = (temp % sistem) + remember;
                remember = temp / sistem;
            }
        } else {
            back.value[i] = temp + remember;
            remember = 0;
        }
    }
    return back;
}

void Big::PrintHex() const{
    for(int i = 0; i < digit; i++){
        printf("%13X", value[i]);
    }
    cout << "\n";
}

void Big::PrintInt() const{
    for(int i = 0; i < digit; i++){
        cout << value[i] << "  ";
    }
    cout << endl;
}

Big Big::operator =(const Big& other){
    if(this->value){
        delete[] this->value;
    }
    this->digit = other.digit;
    this->value = new unsigned int[this->digit];
    for(int i = 0; i < this->digit; i++){
        this->value[i] = other.value[i];
    }
    return *this;
}

int takeHex(string number){
    int value = 0;
    int i = number.size() - 1;
    do{
        switch(number[i]){
            case 'A':{
                value += 10 * pow(16, i);
                break;
            }
            case 'B':{
                value += 11 * pow(16, i);
                break;
            }
            case 'C':{
                value += 12 * pow(16, i);
                break;
            }
            case 'D':{
                value += 13 * pow(16, i);
                break;
            }
            case 'E':{
                value += 14 * pow(16, i);
                break;
            }
            case 'F':{
                value += 15 * pow(16, i);
                break;
            }
            default:{
                value += int(number[i] - '0') * pow(16, i);
            }
        }
    } while(i--);
    return value;
}