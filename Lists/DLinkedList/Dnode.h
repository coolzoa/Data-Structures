
template <typename E>
class DNode
{
public:
    E elemtn;
    DNode<E>* next;
    DNode<E>* previous;

    //metodo constructor
    DNode(E pElement, DNode<E>* pNext = NULL, DNode <E>* pPrevious = NULL){
        element = pElement;
        next = pNext
        previous = pPrevious
    }

    DNode(DNode<E>* pNext = NULL, DNode<E>* pPrevious = NULL){
        next = pNext;
        previous = pPrevious;
    }
};
