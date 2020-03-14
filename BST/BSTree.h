#include "BSTNode.h"
template <typename E>
class BSTree
{
private:
    BSTNode<Key, E>*root;
    int cantNodos = 0;

public:
    E find (Key pKey){
        return findAux(root,pKey);
    }

    void insert (Key pKey, E pElement){
        root = insertAux(root,pKey,pElement);
    }

    E remove(Key, pKey){
        E result = find(pKey;
        root = removeAux(root,pKey);
        return result;
    }



private:
    E findAux(BSTNode<Key, E>*pRoot,Key pKey) throw (runtime_error){
        if (pRoot == NULL){
            throw runtime_error("Key not found");
        }
        if (pKey == pRoot->hetKey()){
            return pRoot->getElement();
        }
        if (pKey < pRoot->getKey()){
            return findAux(pRoot->getLeft(),pKey);
        }else{
            return findAux(pRoot->getRight(),pKey);
        }
    }

    BSTNode<Key, E>* insertAux(BSTNode<Key, E>*,pRoot,Key pKey, E pElement){
        if (pRoot == NULL){
            cantNodos++;
            return new BSTNode<Key, E>(pKey, pElement);
        }
        if (pKey < pRoot->getKey()){
            pRoot->setLeft(insertAux(pRoot->getLeft(),pKey,pElement));
            cantNodos++;
            return pRoot;
        }else{
            pRoot->setRight(insertAux(pRoot->getRight(),pKey,pElement));
            cantNodos++;
            return pRoot;
        }
    }

    BSTNode<Key, E>* removeAux(BSTNode<Key, E>*root, Key pKey) throw(runtime_error){
        if (pRoot == NULL){
            throw runtime_error("Key not found");
        }
        if (pKey < pRoot->getKey()){
            pRoot->setLeft(removeAux(pRoot->getLeft(),pKey));
            cantNodos--;
            return pRoot;
        }
        if (pKey > pRoot->getKey()){
            pRoot->setRight(removeAux(pRoot->getRight(),pKey));
            cantNodos--;
            return pRoot;
        }else{
            if (pRoot->isLeaf()){
                    cantNodos--;
                delete pRoot;
                return NULL;

            }
            if (pRoot->childrenCount()== 1){
                BSTNode<Key, E>* temp = pRoot->getUniqueChild();
                delete pRoot;
                return temp;
            }else{
                BSTNode<Key, E>* successor = pRoot->getSuccessor();
                swap(pRoot,successor);
                if (pRoot->getRight==successor){
                    pRoot->setRight(removeAux(successor,pKey));
                }else{
                    BSTNode<Key, E>*successorParent = pRoot->getRight();
                    while (successorParent->getLeft()!=successor){
                        successorParent = successorParent->getLeft();
                    }
                    sucessorParent->setLeft(removeAux(successor,pKey));
                }
                return pRoot;
            }
        }
    }


};
