#ifndef QUEUE_USING_LINKED_LIST_H_INCLUDED
#define QUEUE_USING_LINKED_LIST_H_INCLUDED

#include <iostream>
using namespace std;

template<class t >
struct Node
{
    t data;
    Node<t>* link;
};
template<class t>
class myQueue
{
    private:
        Node<t>* head;
        Node<t>* tail;
        int length;
    public:
        myQueue();

        void enqueue(const t& data);
        void dequeue();

        void display();

        t getQueueFront();
        t getQueueRare();

        int getLength();

        bool isEmpty();

        ~myQueue();

};
template<class t>
 myQueue<t>:: myQueue()
{
     head = tail = 0;
     length = 0;
}
template<class t>
bool myQueue<t>::isEmpty()
{
     return head == 0;
}
template<class t>
void myQueue<t>::enqueue(const t& data)
{
         Node<t>* newNode = new Node<t>;
         newNode->data = data;
         newNode->link = 0;
         if(head == 0){
                head = tail = newNode;
         }
         else{
            tail->link = newNode;
            tail = newNode;
         }
         length++;

}
template<class t>
void myQueue<t>::dequeue()
{
     if(!isEmpty())
     {
         Node<t>* deleteNode = head;
         head = head->link;
         delete deleteNode;
         length --;

         if(head == 0)
            tail = 0;


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
    if(!isEmpty()){ return head->data; }
}
template<class t>
t myQueue<t>::getQueueRare()
{
    if(!isEmpty()){ return tail->data; }
}

template<class t>
void myQueue<t>::display()
{
    Node<t>* temp = head;
    while(temp != 0)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}
template<class t>
myQueue<t>::~myQueue()
{
     Node<t>* deleteNode = 0;
     while(head != 0)
     {
         deleteNode = head;
         head = head->link;
         delete deleteNode;
     }
     tail = 0;
}
#endif // QUEUE_USING_LINKED_LIST_H_INCLUDED
