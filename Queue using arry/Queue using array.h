#ifndef QUEUE_USING_ARRAY_H_INCLUDED
#define QUEUE_USING_ARRAY_H_INCLUDED
#include<iostream>
using namespace std;

template<class t>
class myQueue
{
    private:
        t* arr;
        int queueFront;
        int queueRare;
        int length;
        int maxSize;
    public:
        myQueue();
        myQueue(int maxSize);

        void enqueue(const t& data);
        void dequeue();

        void display();

        t getQueueFront();
        t getQueueRare();

        int getLength();

        bool isEmpty();
        bool isFull();

        void clearQueue();

        ~myQueue();

};
template<class t>
 myQueue<t>:: myQueue()
{
     arr = new t[50];
     maxSize = 50;
     length = queueFront = 0;
     queueRare = maxSize-1;
}
template<class t>
myQueue<t>:: myQueue(int maxSize)
{
        this->maxSize = maxSize;
        arr = new t[this->maxSize];
        length = queueFront = 0;
        queueRare = maxSize-1;
}
template<class t>
bool myQueue<t>::isEmpty()
{
     return length == 0;
}
template<class t>
bool myQueue<t>::isFull()
{
     return length == maxSize;
}
template<class t>
void myQueue<t>::enqueue(const t& data)
{
     if(!isFull())
     {
         queueRare = (queueRare+1)%maxSize;
         arr[queueRare] = data;
         length++;
     }
     else
        cout<<"Sorry, the queue is full \n";
}
template<class t>
void myQueue<t>::dequeue()
{
     if(!isEmpty())
     {
         queueFront = (queueFront+1)%maxSize;
         length--;
     }
     else
        cout<<"Sorry, Cannot delete from empty queue \n";
}
template<class t>
int myQueue<t>:: getLength()
{
     return length;
}
template<class t>
t myQueue<t>::getQueueFront()
{
    return arr[queueFront];
}
template<class t>
t myQueue<t>::getQueueRare()
{
    return arr[queueRare];
}

template<class t>
void myQueue<t>::display()
{
    if( queueRare >= queueFront){
        for(int i = queueFront ; i<=queueRare ; i++)
            cout<<arr[i]<<" ";
    }
    if(queueRare < queueFront)
    {
        for(int i = queueFront ; i<maxSize ; i++)
            cout<<arr[i]<<" ";
        for(int i = 0 ; i<= queueRare ; i++)
            cout<<arr[i]<<" ";
    }
}
template<class t>
void myQueue<t>::clearQueue()
{
     length = queueFront = 0;
     queueRare = maxSize-1;
}
template<class t>
 myQueue<t>::~myQueue()
{
     delete []arr;
}
#endif // QUEUE_USING_ARRAY_H_INCLUDED
