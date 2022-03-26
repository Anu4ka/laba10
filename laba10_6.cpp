
#include <iostream>
#include <locale.h>
#include <cstring>
#include <math.h>

#include "Big.hpp"

using namespace std;

unsigned int Big::sistem = pow(2, 32);

int main(){
    Big number("5");
    for(int i = 0; i < 100; i++){
        number = number * 5;
    }
    number.PrintHex();
    number.PrintInt();
    return 0;
}