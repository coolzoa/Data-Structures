#include <iostream>
#include "lQueue.h"
#include "AQueue.h"

using namespace std;

int main()
{
    cout <<"-----array Queue -----"<<endl;
    AQueue<int> myQueue(21);
    cout << "queue is full?" << myQueue.isFull() << endl;
    cout << "queueis empty?" << myQueue.isEmpty() << endl;
    for (int i=0; i <= 19;i++){
            cout << "Inserting: " << i << endl;
            myQueue.enqueue(i);
    }
    cout << "First out: " << myQueue.dequeue() << endl;
    cout << "Value in front: " << myQueue.frontValue() << endl;
    cout << "Queue length: " << myQueue.length() << endl;

    cout <<"Linked queue-----"<<endl;

    lQueue <int> linkedQ;

    for (int i = 0;i < 21; i++){
        cout << "Inserting: "<<i<<endl;
        linkedQ.enqueue(i);
    }
    cout << "First in queue: "<< linkedQ.frontValue() <<endl;
    cout <<"Length: "<<linkedQ.length()<<endl;
    cout << "First one exits"<< endl;
    linkedQ.dequeue();
    cout <<"First in queue: "<<linkedQ.frontValue()<<endl;
    return 0;
}
