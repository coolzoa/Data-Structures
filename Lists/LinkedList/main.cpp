#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> myList;

    myList.append(0);
    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.append(40);
    myList.append(50);
    myList.append(60);
    myList.append(70);
    myList.append(80);
    myList.append(90);
    myList.append(100);
    myList.append(110);
    myList.append(120);
    myList.append(130);
    myList.append(140);

    cout << "First 15 numbers added(append)" << endl;

    myList.printList();

    cout << "\tInserting 150 in position 0" << endl;
    myList.goToPos(0);
    myList.insert(150);

    cout << "\tInserting 160 in position 5" << endl;
    myList.goToPos(5);
    myList.insert(160);

    cout << "\tInserting 170 in position 10" << endl;
    myList.goToPos(10);
    myList.insert(170);

    cout << "\tInserting 180 in position 15" << endl;
    myList.goToPos(15);
    myList.insert(180);

    cout << "\tInserting 190 in position 13" << endl;
    myList.goToPos(13);
    myList.insert(190);

    cout << "\tInserting 200 in position 8" << endl;
    myList.goToPos(8);
    myList.insert(200);

    myList.printList();

    cout << "\nDeleting position 10" << endl;
    myList.goToPos(10);
    cout << "Deleted number-> " << myList.remove() << endl;

    myList.printList();

    cout << "\nGoing to start(goToStart)" << endl;
    myList.goToStart();
    cout << "FirstNumber -> " << myList.getElement() << endl;

    cout << "\nGoing to end(goToEnd)" << endl;
    myList.goToEnd();
    myList.previous();
    cout << "Last number -> " << myList.getElement() << endl;

    cout << "\nGoing to position 15(goToPos)" << endl;
    myList.goToPos(15);
    cout << "Position 15 -> " << myList.getElement() << endl;

    cout << "\nGoing to next position(next)" << endl;
    myList.next();
    cout << "next -> " << myList.getElement() << endl;

    cout << "\nGoing to previous positionprevious)" << endl;
    myList.previous();
    cout << "previous -> " << myList.getElement() << endl;

    cout << "\nShowing position (getPos)" << endl;
    cout << "Position -> " << myList.getPos() << endl;

    cout << "\nShowing size(getSize)" << endl;
    cout << "Size -> " << myList.getSize() << endl;
    return 0;
}
