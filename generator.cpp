#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdint>
#include <time.h>

using namespace std;

int main() {
    srand(time(nullptr));
    ofstream out;
    out.open("./numbers.txt");
    double temp = 0;
    if(out.is_open()){
        for(int i = 0; i < 50000; i++){
            out << rand() % 10001 << endl;
        }
    }
	return 0;
}