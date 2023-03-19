#include <iostream>
#include "Queue using array.h"

using namespace std;

int main()
{
    myQueue<int> q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(10);

    q.display();
    cout<<"length = "<<q.getLength()<<endl;
    cout<<q.getQueueFront()<<" "<<q.getQueueRare()<<endl;

    q.dequeue();
    q.dequeue();
    q.enqueue(10);
    q.enqueue(11);

    q.display();
    cout<<"length = "<<q.getLength()<<endl;
    cout<<q.getQueueFront()<<" "<<q.getQueueRare()<<endl;

}
