#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define defaultSize 1024
#include <assert.h>




#endif // STACK_H_INCLUDED

template <typename E>
class AStack{
    private:
        int maxSize;
        int top;
        E *ListArray;

    public:
    AStack(int size = defaultSize){
        maxSize = size;
        top = 0;
        ListArray = new E[size];
    }

    ~AStack() {delete [] ListArray;}

    void clear(){top = 0;}

    void push(E pElement){
        assert(top != maxSize && "Stack empty");
        ListArray[top++] = pElement;
    }

    E pop(){
        assert(top != 0 && "Stack empty");
        return ListArray[--top];
    }

    E topValue(){
        assert (top != 0 && "Stack empty");
        return ListArray[top-1];
    }

    int length(){
        return top;
    }
};
