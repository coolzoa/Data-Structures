#ifndef BSTNODE_H
#define BSTNODE_H

using namespace std;

template <typename Key, typename E>
class BSTNode
{
private:
    Key key;
    E element;
    BSTNode<Key, E>* left;
    BSTNode<Key, E>* right;

public:
    BSTNode(BSTNode<Key, E>* pLeft = NULL, BSTNode<Key, E>* pRight = NULL) {
        left = pLeft;
        right = pRight;
    }

    BSTNode(Key pKey, E pElement, BSTNode<Key, E>* pLeft = NULL, BSTNode<Key, E>* pRight = NULL) {
        key = pKey;
        element = pElement;
        left = pLeft;
        right = pRight;
    }

    ~BSTNode() {}
    E getElement() {
        return element;
    }
    void setElement(E pElement) {
        element = pElement;
    }
    Key getKey() {
        return key;
    }
    void setKey(Key pKey) {
        key = pKey;
    }
    BSTNode<Key, E>* getLeft() {
        return left;
    }
    void setLeft(BSTNode<Key, E>* pLeft) {
        left = pLeft;
    }
    BSTNode<Key, E>* getRight() {
        return right;
    }
    void setRight(BSTNode<Key, E>* pRight) {
        right = pRight;
    }
    bool isLeaf() {
        return (left == NULL) && (right == NULL);
    }
    int childrenCount() {
        return (left == NULL? 0 : 1) + (right == NULL? 0 : 1);
    }
    BSTNode<Key, E>* getUniqueChild() {
        return (left == NULL? right : left);
    }
    BSTNode<Key, E>* getSuccessorAux(BSTNode<Key, E>* pRoot) {
        if (pRoot == NULL) {
            return NULL;
        }
        if (pRoot->left == NULL) {
            return pRoot;
        } else {
            return getSuccessorAux(pRoot->left);
        }
    }
    BSTNode<Key, E>* getSuccessor() {
        return getSuccessorAux(right);
    }
};

#endif // BSTNODE_H
