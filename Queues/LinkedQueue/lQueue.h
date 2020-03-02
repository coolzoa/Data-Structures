#include "Node.h"
#include <stdexcept>
#define DEFAULT_MAXSIZE 1024
using namespace std;


template <typename E>
class lQueue{

private:
    Node<E>* front;
    Node<E>* rear;
    int size;

public:
    lQueue(int size = DEFAULT_MAXSIZE){
        front = rear = new Node<E>();
        size = 0;
    }

    ~lQueue(){
        clear();
        delete front;
    }

    void clear(){
        Node<E>* temp = front->next;
        while (temp!=NULL){
            front->next = front->next->next;
            delete temp;
            rear = front->next;
        }
        rear = front;
        size = 0;

    }

    void enqueue(E pElement){
        rear->next = new Node<E>(pElement);
        rear = rear->next;
        size++;
    }

    E dequeue() throw(runtime_error){
        if (front->next==NULL){
            throw runtime_error("Queue empty");
        }
        Node<E>* temp = front->next;
        E ele = front->next->element;
        front->next = temp->next;
        if (rear == temp){
            rear = front;
        }
        delete temp;
        size--;
        return ele;
    }

    E frontValue() throw(runtime_error){
        if(size==0){
            throw runtime_error("Queue empty");
        }
        return front->next->element;

    }

    int length(){
        return size;
    }

};
