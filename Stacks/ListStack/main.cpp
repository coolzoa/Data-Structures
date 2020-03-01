#include <iostream>
#include <stdexcept>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> myStack;
    for(int i = 0; i < 21; i++){
        myStack.push(i);
    }

    cout << "Showing data" << endl;

    int tam = myStack.getSize();
    for(int i = 0; i < tam; i++){
        cout << "Position <" << i << "> -> Value: " << myStack.pop() << endl;
    }

    cout << "Filling up stack" << endl;

    for(int i = 0; i < 21; i++){
        myStack.push(i);
    }

    cout << "Top value is: " << myStack.topValue() << endl;

    cout << "Erasing stack" << endl;
    myStack.~LinkedStack();

    cout << "Stack is erased..." << endl;

    return 0;
}
