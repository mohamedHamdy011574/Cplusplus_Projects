#ifndef LINKEDLISTSTACK_H_INCLUDED
#define LINKEDLISTSTACK_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

template<class t>
struct Node
{
    t data;
    Node<t>* link;

};

template<class t>
class myStack
{
    private:
        Node<t>* topIndex;
        int mySize;
    public:
        myStack();
        void push(const t& data);
        void pop();
        t top()const;
        int getMySize()const;
        bool isEmpty()const;

        ~myStack();
};
template<class t>
myStack<t>::myStack()
{
    topIndex=0;
    mySize=0;
}


template<class t>
void myStack<t>::push(const t& data)
{

        Node<t>* newNode = new Node<t>;

        newNode->data=data;
        newNode->link=topIndex;
        topIndex=newNode;

        mySize++;

}

template<class t>
void myStack<t>::pop()
{
    if(isEmpty())
    {
        cout<<"sorry, Cannot delete from empty stack"<<endl;
    }
    else
    {
        Node<t>* tempToDelete;

        tempToDelete=topIndex;
        topIndex=topIndex->link;

        delete tempToDelete;

        mySize--;

    }

}

template<class t>
t myStack<t>::top()const
{
    if(isEmpty())
        throw("sorry, your stuck is empty \n");

    else
        return topIndex->data;
}

template<class t>
int myStack<t>::getMySize()const
{
    return mySize;
}

template<class t>
bool myStack<t>::isEmpty()const
{
    return (topIndex == 0);
}

template<class t>
myStack<t>::~myStack()
{

    while(topIndex != 0)
    {
        Node<t>* temp = topIndex;
        topIndex=topIndex->link;
        delete temp;
    }

}
#endif // LINKEDLISTSTACK_H_INCLUDED
