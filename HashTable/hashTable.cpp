#include "hashTable.h"


Hash::Hash() {
    int i;
    for (i = 0; i < hashGroups; i++) {
        hashTable[i] = new item;
        hashTable[i]->key = "";
        hashTable[i]->value = 0;
        hashTable[i]->next = NULL;
    }
}

void Hash::addItem(string key, int value) {
    int index = hashFunction(key);
    //if empty
    if (hashTable[index]->key.compare("") == 0) {
        hashTable[index]->key = key;
        hashTable[index]->value = value;
        cout << "NEW KEY: " << key << " VALUE: " << value << " added" << endl;
    
    } else {
        item* ptr = hashTable[index];
        item* n = new item;
        n->key = key;
        n->value = value;
        n->next = NULL;

        //if first
        if (ptr->key.compare(key) == 0) {
            cout << "WARNING: key " << key << " already exists, updating value to " << value << endl;
            ptr->value = n->value;

        //look through the rest of the list
        } else {
            bool found = false;

            while (ptr->next != NULL) {
                cout << "Key being checked: "  << ptr->key << endl;
                if (ptr->key.compare(key) == 0) {
                    ptr->value = value;
                    found = true;
                    break;
                } else {
                    ptr = ptr->next;
                }
            }

            if (!found) {
                
                ptr->next = n;
                cout << "NEW KEY: " << key << " VALUE: " << value << "added" << endl;
            }
        }
    }
}


int Hash::hashFunction(string key) {
    int hash = 0;
    int i;
    int length = key.length();
    for (i = 0; i < length; i++) {
        hash = hash + (int)key[i];
    }
    return hash % hashGroups;
}

int Hash::numberItemsInIndex(int index) {
    int count = 0;
    if (hashTable[index]->key.compare("") == 0) {
        return count;
    } else {
        count++;
        item* ptr = hashTable[index];
        while (ptr->next != NULL) {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void Hash::printHashTable() {
    int numberItems;
    int i;
    for (i = 0; i < hashGroups; i++) {
        numberItems = numberItemsInIndex(i);
        cout << "------------" << endl;
        cout << "INDEX: " << i << endl;
        cout << "#ITEMS = " << numberItems << endl;
        if (numberItems > 0) {
            printItemsInIndex(i);
        }
    }
}

void Hash::printItemsInIndex(int index) {
    cout << "---ITEMS---" << endl;
    item*ptr = hashTable[index];
    while (ptr != NULL) {
        cout << "KEY: " << ptr->key << " -  VALUE: " << ptr->value << endl;
        ptr = ptr->next;
    }
}

//returns the value associated with the key
int Hash::find(string key) {
    int index = hashFunction(key);
    bool found = false;

    item* ptr = hashTable[index];
    while (ptr != NULL) {
        if (ptr->key.compare(key) == 0) {
            found = true;
            break;
        } else {
            ptr = ptr->next;
        }
    }
    if (!found) {
        cout << "No value associated to key: " << key << " found" << endl;
        return -1;
    } else {
        return ptr->value;
    }
}



int main() {
    Hash h;
    h.addItem("Alex", 0);
    h.addItem("Alex", 1);
    h.addItem("Jones", 101);
    h.addItem("Stan", 500);
    h.printHashTable();
    cout << h.find("Alex") << endl;
    cout << h.find("James") << endl;
    return 0;
}