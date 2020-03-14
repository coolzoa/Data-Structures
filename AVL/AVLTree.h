#ifndef AVLTREE_H
#define AVLTREE_H
#include "BSTNode.h"
#include <stdexcept>
#include <cmath>

using namespace std;

template <typename Key, typename E>
class AVLTree
{
private:
    BSTNode<Key, E>* root;

    void inOrderAux(BSTNode<Key, E>* pRoot) {
        if (pRoot == NULL) {
            return;
        }
        inOrderAux(pRoot->getLeft());
        cout << pRoot->getElement() << " ";
        inOrderAux(pRoot->getRight());
    }
    void preOrderAux(BSTNode<Key, E>* pRoot) {
        if (pRoot == NULL) {
            return;
        }
        cout << pRoot->getElement() << " ";
        preOrderAux(pRoot->getLeft());
        preOrderAux(pRoot->getRight());
    }
    void printAux(BSTNode<Key, E>* pRoot, int depth) {
        if (pRoot == NULL) {
            return;
        }
        for (int i = 0; i < depth; i++) {
            cout << "  ";
        }
        cout << "+-" << pRoot->getKey() << endl;
        printAux(pRoot->getLeft(), depth + 1);
        printAux(pRoot->getRight(), depth + 1);
    }
    BSTNode<Key, E>* insertAux(BSTNode<Key, E>* pRoot,
                               Key pKey,
                               E pElement) throw(runtime_error) {
        if (pRoot == NULL) {
            return new BSTNode<Key, E>(pKey, pElement);
        }
        if (pKey < pRoot->getKey()) {
            pRoot->setLeft(insertAux(pRoot->getLeft(), pKey, pElement));
            return rebalanceLeft(pRoot);
        } else {
            if (pKey > pRoot->getKey()) {
                pRoot->setRight(insertAux(pRoot->getRight(), pKey, pElement));
                return rebalanceRight(pRoot);
            } else {
                throw runtime_error("Llave ya existe, no se pueden valores repetidos.");
            }
        }
    }

    BSTNode<Key, E>* rebalanceLeft(BSTNode<Key, E>* pRoot) {

        int heightLeft = height(pRoot->getLeft());
        int heightRight = height(pRoot->getRight());
        if ((heightLeft-heightRight)>1){
            int heightLeftLeft = height(pRoot->getLeft()->getLeft());
            int heightLeftRight = height(pRoot->getLeft()->getRight());
            if(heightLeftLeft >=heightLeftRight){
                return rotateRight(pRoot);
            }else{
                pRoot->setLeft(rotateLeft(pRoot->getLeft()));
                return rotateRight(pRoot);
            }
        }
        return pRoot;
    }

    BSTNode<Key, E>* rebalanceRight(BSTNode<Key, E>* pRoot) {

        int heightLeft = height(pRoot->getLeft());
        int heightRight = height(pRoot->getRight());
        if ((heightRight-heightLeft)>1){
            int heightRightRight = height(pRoot->getRight()->getRight());
            int heightRightLeft = height(pRoot->getRight()->getLeft());
            if(heightRightRight >= heightRightLeft){
                return rotateLeft(pRoot);
            }else{
                pRoot->setRight(rotateRight(pRoot->getRight()));
                return rotateLeft(pRoot);
            }
        }
        return pRoot;
    }

    E findAux(BSTNode<Key, E>* pRoot, Key pKey) throw (runtime_error) {
        if (pRoot == NULL) {
            throw runtime_error("No se encuentra la llave.");
        }
        if (pKey == pRoot->getKey()) {
            return pRoot->getElement();
        }
        if (pKey < pRoot->getKey()) {
            return findAux(pRoot->getLeft(), pKey);
        } else {
            return findAux(pRoot->getRight(), pKey);
        }
    }
    BSTNode<Key, E>* removeAux(BSTNode<Key, E>* pRoot, Key pKey) throw (runtime_error) {
        if (pRoot == NULL) {
            throw runtime_error("No se encuentra la llave.");
        }
        if (pKey < pRoot->getKey()) {
            pRoot->setLeft(removeAux(pRoot->getLeft(), pKey));
            if (pRoot->getLeft() != NULL) {
                pRoot = rebalanceLeft(pRoot);
            }
            return pRoot;
        }
        if (pKey > pRoot->getKey()) {
            pRoot->setRight(removeAux(pRoot->getRight(), pKey));
            if (pRoot->getRight() != NULL) {
                pRoot = rebalanceRight(pRoot);
            }
            return pRoot;
        } else {
            if (pRoot->isLeaf()) {
                delete pRoot;
                return NULL;
            }
            if (pRoot->childrenCount() == 1) {
                BSTNode<Key, E>* temp = pRoot->getUniqueChild();
                delete pRoot;
                return temp;
            } else {
                BSTNode<Key, E>* successor = pRoot->getSuccessor();
                swap(pRoot, successor);
                if (pRoot->getRight() == successor) {
                    pRoot->setRight(removeAux(successor, pKey));
                } else {
                    BSTNode<Key, E>* succesorParent = pRoot->getRight();
                    while (succesorParent->getLeft() != successor) {
                        succesorParent = succesorParent->getLeft();
                    }
                    succesorParent->setLeft(removeAux(successor, pKey));
                }
                return pRoot;
            }
        }
    }
    void swap(BSTNode<Key, E>* pNode1, BSTNode<Key, E>* pNode2) {
        Key tempK = pNode1->getKey();
        E tempE = pNode1->getElement();
        pNode1->setKey(pNode2->getKey());
        pNode1->setElement(pNode2->getElement());
        pNode2->setKey(tempK);
        pNode2->setElement(tempE);
    }
    // Método que realiza una rotación hacia la derecha en el nodo actual
    BSTNode<Key, E>* rotateRight(BSTNode<Key, E>* pRoot) throw(runtime_error) {
        if(pRoot == NULL){
        throw runtime_error("No se puede rotar Nulo");
        }
        if(pRoot -> getLeft() == NULL){
            throw runtime_error("No se puede rotar a la derecha con el hijo izquierdo nulo");
        }
        BSTNode<Key, E>* newRoot = pRoot->getLeft();
        pRoot -> setLeft(newRoot -> getRight());
        newRoot ->setRight(pRoot);
        return newRoot;
    }

    // Método que realiza una rotación hacia la izquierda en el nodo actual
    BSTNode<Key, E>* rotateLeft(BSTNode<Key, E>* pRoot) throw(runtime_error) {
        if(pRoot == NULL){
            throw runtime_error("No se puede rotar Nulo");
        }
        if(pRoot -> getRight() == NULL){
            throw runtime_error("No se puede rotar a la izquierda con el hijo derecho nulo");
        }
        BSTNode<Key, E>* newRoot = pRoot->getRight();
        pRoot -> setRight(newRoot -> getLeft());
        newRoot ->setLeft(pRoot);
        return newRoot;
    }

    BSTNode<Key, E>* rotateLeftTwice(BSTNode<Key, E>* node){
        rotateRight(node->getLeft());
        rotateLeft(node);
    }

    int height(BSTNode<Key, E>* pRoot) {
        if (pRoot == NULL) {
            return 0;
        }
        if (pRoot->isLeaf()) {
            return 1;
        }
        int leftHeight = height(pRoot->getLeft());
        int rightHeight = height(pRoot->getRight());
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
    BSTNode<Key, E>* clear(BSTNode<Key, E>* pRoot) {
        if (pRoot == NULL) {
            return NULL;
        }
        if (pRoot->isLeaf()) {
            delete pRoot;
            return NULL;
        }
        pRoot->setLeft(clear(pRoot->getLeft()));
        pRoot->setRight(clear(pRoot->getRight()));
        delete pRoot;
        return NULL;
    }

public:
    AVLTree() {
        root = NULL;
    }
    ~AVLTree() {
        root = clear(root);
    }
    void insert(Key pKey, E pElement) {
        root = insertAux(root, pKey, pElement);
    }
    void inOrder() {
        inOrderAux(root);
        cout << endl;
    }
    void preOrder() {
        preOrderAux(root);
        cout << endl;
    }
    E find(Key pKey) {
        return findAux(root, pKey);
    }
    E remove(Key pKey) {
        E result = find(pKey);
        root = removeAux(root, pKey);
        return result;
    }
    void print() {
        printAux(root, 0);
    }
};

#endif // AVLTREE_H
