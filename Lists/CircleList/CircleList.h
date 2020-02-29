#ifndef CIRCLELIST_H_INCLUDED
#define CIRCLELIST_H_INCLUDED

#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename E>
class CircleList
{
    private:
        Node <E> *cursor;
        Node <E> *header;  // Special node to know it is the first element of the list

    public:
        CircleList(){
            cursor = header = NULL;
        }

        ~CircleList(){
            while(!empty()){
                remove();
            }
        }

        bool empty(){
            return cursor == NULL;
        }

        //returns element right after the cursor
        E front() throw (range_error) {
            if(cursor == NULL){
                throw range_error("Empty list!");
            }
            return cursor->next->element;
        }

        //returns element referenced by cursor
        E back() throw (range_error) {
            if(cursor == NULL){
                throw range_error("Empty list!");
            }
            return cursor->element;
        }

        void advance(){
            cursor = cursor->next;
        }

        //adds element aftet the cursor, else it creates a node that points to itself
        void add(E pElement){
            if(cursor == NULL){
                cursor = new Node<E>(pElement);
                cursor->next = cursor;
            } else {
                cursor->next = new Node<E>(pElement, cursor->next);
            }
        }

        //returns element right after the cursor
        E remove() throw (range_error){
            if(cursor == NULL){
                throw range_error("Empty list!");
            }
            E result = cursor->next->element;
            Node<E> *temp = cursor->next;
            if(cursor == temp){
                cursor = NULL;
            } else {
                cursor->next = cursor->next->next;
            }
            delete temp;
            return result;
        }

        void printList(){
            cout << "Showing list" << endl;
            for(int i = 0; i < 21; i++){
                cout << "[" << front() << "]";
                advance();
            }
            cout << endl;
        }

};
#endif // CIRCLELIST_H_INCLUDED
