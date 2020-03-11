
#include "Heap.h"
#include <iostream>
using namespace std;

int main() {
    Heap h(10);
    h.add(3);
    h.display();
    h.add(2);
    h.display();
    h.add(1);
    h.display();

    cout << "Extracting the root from heap" << endl;
    int r = h.GetRoot();
    cout << "Root extracted: " << r << endl;
    cout << "New heap" << endl;
    h.display();

    return 0;
}