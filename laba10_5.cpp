
#include "Tree.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "Belarusian");
    srand(time(nullptr));
    Tree tree;
    cout << "Enter number of elements: ";
    int isize = 0;
    cin >> isize;
    for(int i = 0; i < isize; i++){
        tree.pushback(rand() % 100);
    }
    tree.print();
    int maxdepth = tree.GetMaxDepth();
    cout << "Max depth is: " << maxdepth;
    return 0;
}