#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename E>

class LinkedStack{
private:
    Node<E>* top;
    int size;

public:
    LinkedStack(){
        top = new Node<E>();
        size = 0;
    }

    ~LinkedStack(){
        clear();
        delete top;
    }

    void push(E pElement){
        top = new Node<E> (pElement, top);
        size++;
    }

    E pop() throw (runtime_error){
        if(top == NULL){
            throw runtime_error("Empty stack!");
        }
        E result = top->element;
        Node<E>* temp = top;
        top = top->next;
        delete temp;
        size --;
        return result;
    }

    E topValue() throw(runtime_error){
        if(top == NULL){
            throw runtime_error("Empty stack!");
        }
        return top->element;
    }

    int getSize(){
        return size;
    }

    void clear(){
        while (top != NULL) {
            Node<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

};

#endif // LINKEDSTACK_H_INCLUDED
