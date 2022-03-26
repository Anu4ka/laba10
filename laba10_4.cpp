
#include <iostream>
#include <locale.h>
#include <cstring>

#include "C-strings.hpp"


using namespace std;

int main(){
    setlocale(LC_ALL, "Belarusian");
    cout << "Enter first string: ";
    char* originalstring = new char[256];
    cin.getline(originalstring, 256);
    cout << "Enter sub-string that u want to replace: ";
    char* offstring = new char[256];
    cin.getline(offstring, 256);
    cout << "Enter new sub-string: ";
    char* onstring = new char[256];
    cin.getline(onstring, 256);
    Cstring str(originalstring);
    Cstring prev(str);
    do{
        prev = str;
        str = str - offstring;
        str = str + onstring;
    } while (prev != str);
    str.Print();
    
    delete[] onstring;
    delete[] offstring;
    delete[] originalstring;
    return 0;
}