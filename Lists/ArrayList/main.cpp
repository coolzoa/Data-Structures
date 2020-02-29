#include "array.h"

int main() {
    ArrayList<int> list1(10);
    list1.append(5);
    list1.insert(7);
    list1.goToStart();
    list1.insert(8);
    list1.next();
    int a = list1.remove();
    cout << a;
    return 0;
}