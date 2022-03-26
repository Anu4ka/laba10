#include <iostream>
#include <cmath>
#include <cstring>
#include <string.h>
#include <iomanip>

#include "vector.hpp"
#include "Matrix.hpp"

using namespace std;

int Matrix::counter = 0;

int main(){
    setlocale(LC_ALL, "Belarusian");
    srand(time(nullptr));
    cout << " Enter matrix size: ";
    int isize = 0;
    cin >> isize;
    cout << "Enter max power: ";
    int ipower = 0;
    cin >> ipower;
    Matrix matrix(isize);
    try{
        matrix.fillrandomly();
    } catch(exception err) {
        cout << err.what() << endl;
        return 1;
    }
    matrix.Print();
    Matrix newmatrix(isize);
    try{
        newmatrix = work(matrix, ipower);
    } catch(exception err) {
        cout << err.what() << endl;
        return 1;
    }
    newmatrix.Print();
    cout << "total number of created matrixes is: " << Matrix::counter;
    return 0;
}