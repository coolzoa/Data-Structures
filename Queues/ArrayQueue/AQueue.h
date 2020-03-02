
#define DEFAULT_MAXSIZE 1024

#include <stdexcept>



using namespace std;



template <typename E>

class AQueue{

private:

    int maxSize;
    int front;
    int back;
    int size;

    E* listArray;



public:

    AQueue(int size = DEFAULT_MAXSIZE){

        maxSize=size+1;
        back=0;
        front=1;
        listArray=new E [maxSize];
    }



    ~AQueue(){
        delete [] listArray;
    }



    bool isFull(){

        return(back+2) % maxSize == front;

    }



    bool isEmpty(){

        return (back+1)%maxSize ==front;

    }



    void enqueue(E pElement) throw(runtime_error) {

        if (isFull()){

                throw runtime_error("Queue is full.");

        }

        back = (back+1) % maxSize;

        listArray[back] = pElement;

        size++;

    }

    E dequeue() throw(runtime_error) {

        if (isFull()){

                throw runtime_error("Queue is full.");

        }

        E res=listArray[front];

        front = (front+1) % maxSize;

        size--;

        return res;

    }



    void clear(){

        back=0;

        front=1;

    }



    E frontValue()throw(runtime_error){

        if (isEmpty()){

                throw runtime_error("Queue is empty.");



        }

        return listArray[front];

    }



    int length(){

        return ((back+maxSize)-front+1)%maxSize;

    }
};

