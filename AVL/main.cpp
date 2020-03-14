#include <iostream>
#include "include\AVLTree.h"

using namespace std;

int main()
{
    AVLTree<int, int>* t = new AVLTree<int, int>();

    for (int i = 1; i<10; i++) {
        t->insert(i, i);
    }

    t->print();
    cout << endl;
    delete t;
    return 0;
}
