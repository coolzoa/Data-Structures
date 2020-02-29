#include <stdexcept>
#include "DNode.h"

using namespace std;

template <typename E>
class DLinkedList
{
    private:
        DNode <E>* head;
        DNode <E>* tail;
        DNode <E>* current;
        int size;

        void init(){
            head = new DNode<E>();
            tail = new DNode<E>();
            current = new DNode<E>();
            size = 0;
        }

    public:
        DLinkedList(){
            init();
        }
        ~DLinkedList(){
            clear();
            delete head;
            delete tail;
        }

        void insert(E pElement){
            current->next = current->next->previous = new DNode<E>(pElement, current->next,current);
            size++;
        }

        void append(E pElement){
            tail->previous = tail->previous->next = new DNode<E>(pElement,tail,tail->previous);
            size++;
        }

        E remove() throw (runtime_error){
            if (current->next == tail){
                throw runtime_error("No element to remove.");
            }
            DNode<E>* temp = current->next;
            current->next = current->next->next;
            current->next->previous = current
            delete temp
            size--;
        }

        void clear(){
            while (head != NULL){
                current = head;
                head = head->next;
                delete current;
            }
            init();
        }

        E getElement() throw(runtime_error){
            if (current->next == tail){
                throw runtime_error("No element to get");
            }
            return current->next->element;
        }

        void goToStart(){
            current = head;
        }

        void goToEnd(){
            current = tail->previous;
        }

        void goToPos(int pPos) throw(runtime_error){
            if (pPos < 0 || pPos >= size){
                throw runtime_error("Index out of range");
            }
            current = head;
            for (int i = 0; i < pPos; i++){
                current = current->next;
            }
        }

        void next(){
            if (current != tail->previous){
                current = current->next;
            }
        }

        void previous(){
            if (current != head){
                current = current->previous;
            }
        }

        int getPos(){
            int pos = 0
            DNode<E>* temp = head;
            while (temp != current){
                temp = temp->next;
                pos++;
            }
            return pos;
        }

        int getSize(){
            return size;
        }
};

