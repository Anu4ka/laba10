#include <iostream>
#include <exception>
#include "List.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "Belarusian");
    List* firstList = new List();
    cout << "Enter number of first list elements: ";
    int isize1 = 0;
    cin >> isize1;
    cout << "Enter first list elements: ";
    for(int i = 0; i < isize1; i++){
        char value = '0';
        cin >> value;
        firstList->push_back(value);
    }
    List* secondList = new List();
    cout << "Enter number of second list elements: ";
    int isize2 = 0;
    cin >> isize2;
    cout << "Enter second list elements: ";
    for(int i = 0; i < isize2; i++){
        char value = '0';
        cin >> value;
        secondList->push_back(value);
    }
    List* newList = new List();
    firstList->GetUnicElements(secondList, newList);
    cout << "New list is: ";
    newList->Print();
    return 0;
}