
#include "C-strings.hpp"
#include <iostream>
#include <cstring>

using namespace std;

Cstring::Cstring(){
    originalsize = 0;
    original = new char[256];
}

Cstring::Cstring(char* original){
    originalsize = strlen(original);
    this->original = new char[256];
    this->original = original;
}

Cstring::Cstring(Cstring& other){
    this->originalsize = other.originalsize;
    original = new char[originalsize];
    for(int i = 0; i < originalsize; i++){
        original[i] = other.original[i];
    }
}

Cstring::~Cstring(){
    delete[] this->original;
}

Cstring& Cstring::operator=(const Cstring& other){
    if(this->original){
        delete [] this->original;
    }
    original = new char[256];
    this->originalsize = other.originalsize;
    for(int i = 0; i < originalsize; i++){
        original[i] = other.original[i];
    }
    return *this;
}

void Cstring::copypaste(int begin, int end, char* other){
    for(int i = begin; i < end; i++){
        this->original[originalsize++] = other[i];
    }
}

Cstring Cstring::operator-(char* other){
    int othersize = strlen(other);
    char* first_char = strstr(original, other);
    int iposition = (first_char - original) / sizeof(char);
    if(first_char == nullptr){
        return *this;
    }
    Cstring temp;
    temp.copypaste(0, iposition, this->original);
    temp.copypaste(0, 1, "0");
    temp.copypaste(iposition + othersize, originalsize, this->original);
    originalsize = strlen(original);
    return temp;
}

Cstring Cstring::operator+(char* other){
    int othersize = strlen(other);
    char* first_char = strstr(original, "0");
    int iposition = (first_char - original) / sizeof(char);
    if(first_char == nullptr){
        return *this;
    }
    Cstring temp;
    temp.copypaste(0, iposition, this->original);
    temp.copypaste(0, strlen(other), other);
    temp.copypaste(iposition + 1, originalsize, this->original);
    temp.originalsize = strlen(original);
    return temp;
}

bool Cstring::operator!=(Cstring& other){
    for(int i = 0; i < originalsize; i++){
        if(original[i] != other.original[i]){
            return true;
        }
    }
    return false;
}

void Cstring::Print(){
    for(int i = 0; i < originalsize; i++){
        cout << original[i];
    }
    cout << "\n";
}

void replace(Cstring& str, char* replace, char* push){

}