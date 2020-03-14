
template <typename Key, typename E>
class BSTNode
{
private:
    Key key;
    E element;
    BSTNode<Key, E>*left;
    BSTNode<Key, E>*right;

public:
    BSTNode(BSTNode<Key,E>* pLeft=NULL, BSTNode<Key E>*pRight=NULL){
        left = pLeft;
        right = pRight;
    }

    BSTNode(Key pKey, E pElement, BSTNode<Key E>* pLeft=NULL,
            BSTNode<Key E>*pRight=NULL){
            key = pKey;
            element = pElement;
            left = pLeft;
            right = pRight;
            }

    ~BSTNode(){}

    E getElement(){
        return element;
    }

    void setElement(E pElement){
        element = pElement;
    }

    Key getKey(){
        return key;
    }

    void setKey(Key pKey){
        key = pKey;
    }

    BSTNode<Key, E>* getLeft(){
        return left;
    }

    void setLeft(BSTNode<Key, E>*pLeft){
        left = pLeft;
    }

    BSTNode<Key, E>* getRight(){
        return right;
    }

    void setRight(BSTNode<Key, E>* pRight){
        right = pRight;
    }

    bool isLeaf(){
        return (left==NULL)&&(right==NULL);
    }

     int childrenCount(){
        if (getLeft() != NULL && getRight()!= NULL){
            return 2;
        }else if(getLeft() != NULL || getRight()!=NULL){
            return 1;
        }else{
            return 0;
        }

        BSTNode<Key, E>* getUniqueChild(){
            if (left == NULL){
                return right;
            }else{
                return left;
            }
        }

        BSTNode<Key, E>* getSuccessor(){
            if (parent == NULL){
                return NULL;
            }else{
                BSTNode<Key,E>*temp = left;
                while (temp!=NULL){
                    temp = left->getLeft();
                }
                return temp;
            }
        }
    }
};
