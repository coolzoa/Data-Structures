#include <iostream>
#include "CircleList.h"

using namespace std;

int main()
{
    CircleList<int> cList;
    for(int i = 0; i < 21; i++){
        cList.add(i);
    }
    cout << "Added 21 elements!" << endl;
    print();

    cout << "Is list empty?" << endl;
    cout << cList.empty() << endl;

    cout << "Current element: " << cList.front() << endl;
    cout << "Going to front" << endl;
    cList.advance();
    cout << "Current element: " << cList.front() << endl;
    cout << "Previous element: " << cList.back() << endl;

    cout << "Removing current element: " << cList.remove() << endl;

    cList.printList();

    return 0;
}
