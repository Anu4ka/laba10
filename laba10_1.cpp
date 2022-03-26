#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <exception>

#include "vector.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "Belarusian");
    srand(time(nullptr));
    const int isize = 10001;
    Vector arr(isize);
    ifstream file("./numbers.txt");
    if (file.is_open()) {
        int temp = 0;
        while (file >> temp) {
            try {
                arr[temp]++;
            } catch (exception err){
                cout << err.what() << endl;
                return 1;
            }
        }
    }
    printeq2(arr);
    return 0;
}