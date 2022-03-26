#include <locale.h>
#include <iostream>
#include <exception>

#include "doubleList.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "Belarusian");
    dList* List = new dList();
    cout << "Enter n: ";
    int n = 0;
    cin >> n;
    List->Setisize(n);
    cout << " Enter youre elemenys: ";
    List->filldList();
    int sum = DoSMT(List)
    return 0;
}