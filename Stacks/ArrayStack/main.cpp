#include "Stack.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int main()
{
   AStack <int> myStack(1000);
   for (int i = 0; i < 21; i++){
        cout << "Inserting: " << i << endl;
        myStack.push(i);
   }
   cout << "Top is: " << myStack.topValue() << endl;
   myStack.pop();
   cout << "Removing top" << endl;
   cout << "New top is: " << myStack.topValue() << endl;
   cout << "Stack length: " << myStack.length() << endl;
   cout << "Inserting 100 "<< endl;
   myStack.push(100);
   cout << "New Length: " << myStack.length() << endl;
   cout << "Emptying stack" << endl;
   myStack.clear();
   cout << "New stack length: " << myStack.length() << endl;
   return 0;

}
