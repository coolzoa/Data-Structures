#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>

using namespace std;

class Hash {
    private:
        static const int hashGroups = 10;

        struct item {
            string key;
            int value;
            item* next;
        };

        item* hashTable[hashGroups];


    public:

        Hash();
        void addItem(string key, int value);
        int hashFunction(string key);
        int numberItemsInIndex(int index);
        void printHashTable();
        void printItemsInIndex(int index);
        int find(string key);
};

#endif