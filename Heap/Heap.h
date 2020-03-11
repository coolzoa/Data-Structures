#ifndef HEAP_H
#define HEAP_H
#include <iostream>

class Heap {
    private:
        int* heapArray; // An array of integers, allocated through the constructor
        int capacity;
        int currentSize;

        void initializeArray(int* arr, int size);
        
        void swap(int* i, int* j); // Swaps two nodes in the heap
        int parent(int i); // Returns the index of the parent of node i (i/2)  ; -1 if out of range
        int left(int i); // Returns the index of the left son of node i (2*i) ; -1 if out of range
        int right(int i); // Returns the index of the right son of node i (2*i + 1) ; -1 if out of range


    public:
        Heap(int max); // max is the number of cells in the array
        ~Heap(); // Needs a destructor to free dynamic mem

        
         int GetRoot(); // Gets the value of the root element and removes it from the heap
         int add(int i); // adds a new element ; returns 0 if success, -1 if failure
         void display(); // Text display, for debug purposes mainly
         void MinHeapify(int i); //heapifies a subtree with root at index, assumes subtrees are already heapified

};

#endif