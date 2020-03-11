#include "Heap.h"
#include <iostream>
using namespace std;

void Heap::swap(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}


int Heap::parent(int i) {    
    int index = (i - 1) / 2;
    if (index < 0 || index >= capacity || index >= currentSize) {
        index = -1;
    }
    return index;
}

int Heap::left(int i) {
    int index = 2 * i + 1;
    return index;
}

int Heap::right(int i) {
    int index = 2 * i + 2;
    return index;
}


Heap::Heap(int max) {
    heapArray = new int[max];
    currentSize = 0;
    capacity = max;
}

Heap::~Heap() {
    delete [] heapArray;
}

int Heap::GetRoot() {
    if (currentSize <= 0) {
        return -1;
    } else if (currentSize == 1) {
        currentSize--;
        return heapArray[0];
    } else {
        int root = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        MinHeapify(0);
        return root;
    }
}

void Heap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);

    int minimum = i;
    if (l < currentSize && heapArray[l] < heapArray[i]) {
        minimum = l;
    }
    if (r < currentSize && heapArray[r] < heapArray[minimum]) {
        minimum = r;
    }
    if (minimum != i) {
        swap(&heapArray[i], &heapArray[minimum]);
        MinHeapify(minimum);
    }
}

int Heap::add(int i) {
    if (currentSize == capacity) {
        std::cout << "OVERFLOW: cannot insert number: " << i << endl;
    } else {
        currentSize++;
        int index = currentSize - 1;
        heapArray[index] = i;

        while (index != 0 && heapArray[parent(index)] > heapArray[index]) {
            swap(&heapArray[index], &heapArray[parent(index)]);
        }
        cout << i << " added successfully" << endl;
        return 0;
    }
    return -1;
}

void Heap::display() {
    int i = 0;
    int l, r, p, root;

    if (currentSize == 0) {
        cout << "No data to show" << endl;
    } else {
        root = heapArray[0];
        cout << "ROOT: " << root << endl;

        while (i < currentSize) {
            p = parent(i);
            l = left(i);
            r = right(i);
            if (p != -1 && p != 0) {
                cout << "Parent: " << heapArray[p] << endl;
            }
            if (heapArray[p] != heapArray[l]) {
                cout << "Left: " << heapArray[l] << endl;
            }
            if (heapArray[p]  != heapArray[r]) {
                cout << "Right: " << heapArray[r] << endl;
            }
            i = i + 3;
        }
    }
}



