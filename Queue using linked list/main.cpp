#include <iostream>
#include "Queue using linked list.h"
#include <exception>
using namespace std;

int main()
{
    myQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();
    cout<<" length = "<<q.getLength()<<" "<<q.getQueueFront()<<" "<<q.getQueueRare()<<endl;

    q.dequeue();
    q.dequeue();

    q.display();
    cout<<" length = "<<q.getLength()<<" "<<q.getQueueFront()<<" "<<q.getQueueRare();



}
