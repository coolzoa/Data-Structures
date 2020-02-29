#ifndef ARRAY_H_
#define ARRAY_H_

#define DEFAULT_MAX_SIZE 1024

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename E> class ArrayList {
    
    private:
        E* elements; //pointer to element array
        int max; //max array element size
        int size; //current array size
        int pos; //current position
    
    public:
        ArrayList(int pMax = DEFAULT_MAX_SIZE) {
            elements = new E[pMax];
            max = pMax;
            size = 0;
            pos = 0;
        }

        virtual ~ArrayList() {
            delete [] elements;
        }

        void insert(E element) throw(runtime_error) {
            if (size == max) {
                throw runtime_error("List full");
            }
            for (int i = size; i > pos; i--) {
                elements[i] = elements[i - 1];
            }
            elements[pos] = element;
            size++;
        }

        void append(E pElement) throw(runtime_error) {
            if (size == max) {
                throw runtime_error("List full");
            }
            elements[size] = pElement;
            size++;
        }

        E remove() throw(runtime_error) {
            if (size == 0) {
                throw runtime_error("Empty list");
            }
            if ((pos < 0) || (pos >= size)) {
                throw runtime_error("Index out of bounds");
            }
            E res = elements[pos];
            for (int i = pos; i < size - 1; i++) {
                elements[i] = elements[i + 1];
            }
            size--;
            return res;
        }

        void clear() {
            size = 0;
            pos = 0;
            delete [] elements;
            elements = new E[max];
        }

        E getElement() throw(runtime_error) {
            if ((pos < 0) || (pos >= size)) {
                throw runtime_error("Index out of bounds");
            }
            return elements[pos];
        }

        void goToStart() {
            pos = 0;
        }

        void goToEnd() {
            pos = size;
        }

        void goToPos(int nPos) throw(runtime_error) {
            if ((nPos < 0) || (nPos > size)) {
                throw runtime_error("Index out of bounds");
            }
            pos = nPos;
        }

        void previous() {
            if (pos > 0) {
                pos--;
            }
        }

        void next() {
            if (pos < size) {
                pos++;
            }
        }

        int getPos() {
            return pos;
        }

        int getSize() {
            return size;
        }
};

#endif