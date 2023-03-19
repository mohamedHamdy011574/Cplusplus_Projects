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
        myStack(int);
        myStack(const myStack<t>&);

        void push(const t& data);
        void pop();
        t top()const;
        int getMySize()const;
        bool isEmpty()const;
        bool isFull()const;

        myStack<t> operator=(const myStack<t>&);

        template<class t1>
        friend ostream& operator<<(ostream& os,const myStack<t1>& rightObj)
        {
            bool flag;
            os<<"you want to print it from top to start  or from start to top : 0:from start , 1>:from top: ";
            cin>>flag;

            Node<t>* currentNode = rightObj.topIndex;

            if(flag !=0){

                while(currentNode != 0)
                {
                    os<<currentNode->data<<" ";
                    currentNode=currentNode->link;
                }

            }
            else{
                    t arr[rightObj.mySize];
                    int i=0;
                    while(currentNode !=0)
                    {
                        arr[i++]=currentNode->data;
                        currentNode=currentNode->link;
                    }
                    for( i=rightObj.mySize-1;i>=0;i--)
                    {
                        os<<arr[i]<<" ";
                    }
            }
            os<<endl;
            return os;
        }
        ~myStack();
};
template<class t>
myStack<t>::myStack()
{
    topIndex=0;
    mySize=0;
}

template<class t>
myStack<t>::myStack(int stackSize)
{
    topIndex=0;
    mySize=0;

    while(stackSize!=0)
    {
        Node<t>* newNode = new Node<t>;
        cout<<"enter the data of the node number "<<mySize+1<<" : ";
        cin>>newNode->data;

        if(topIndex == 0)
        {
            topIndex=newNode;
            topIndex->link=0;
        }
        else
        {
            newNode->link=topIndex;
            topIndex=newNode;
        }
        mySize++;
        stackSize--;
    }
}

template<class t>
myStack<t>::myStack(const myStack<t>& rightObj)
{
        topIndex=0;

        mySize = rightObj.mySize;
        if(rightObj.topIndex == 0)
            topIndex=0;
        else{

        }
    if(rightObj.topIndex !=0)
    {

        mySize=rightObj.mySize;

        Node<t>* currentNode = rightObj.topIndex;
       /* while(currentNode !=0)
        {
            Node<t>* newNode = new Node<t>;
            newNode->data=currentNode->data;
            if(topIndex == 0)
            {
                topIndex=newNode;
                topIndex->link=0;
            }
            else
            {
                newNode->link=topIndex;
                topIndex=newNode;
            }
            currentNode=currentNode->link;
        }*/
        t arr[mySize];
        int i=0;
        while(currentNode !=0)
        {
            arr[i++]=currentNode->data;
            currentNode=currentNode->link;
        }
        for(i=mySize-1;i>=0;i--)
        {
            Node<t>* newNode = new Node<t>;
            newNode->data=arr[i];
            if(topIndex == 0)
            {
                topIndex=newNode;
                topIndex->link=0;
            }
            else
            {
                newNode->link=topIndex;
                topIndex=newNode;
            }
        }

    }

}

template<class t>
void myStack<t>::push(const t& data)
{
    if(isFull())
    {
        cout<<"sorry, Cannot add to a full stack"<<endl;
        return;
    }
    else
    {
        Node<t>* newNode = new Node<t>;

        newNode->data=data;
        newNode->link=topIndex;
        topIndex=newNode;

        mySize++;
    }

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
bool myStack<t>::isFull()const
{
    return false;
}
template<class t>
myStack<t> myStack<t>::operator=(const myStack<t>& rightObj)
{
    if(&rightObj != this)
    {
        while(topIndex!=0)
        {
            Node<t>* temp = topIndex;
            topIndex=topIndex->link;
            delete temp;

        }
        mySize=0;
    }
    if(rightObj.topIndex !=0)
    {

        mySize=rightObj.mySize;

        Node<t>* currentNode = rightObj.topIndex;
       /* while(currentNode !=0)
        {
            Node<t>* newNode = new Node<t>;
            newNode->data=currentNode->data;
            if(topIndex == 0)
            {
                topIndex=newNode;
                topIndex->link=0;
            }
            else
            {
                newNode->link=topIndex;
                topIndex=newNode;
            }

            currentNode=currentNode->link;

        }*/

        t arr[mySize];
        int i=0;
        while(currentNode !=0)
        {
            arr[i++]=currentNode->data;
            currentNode=currentNode->link;
        }
        for(i=mySize-1;i>=0;i--)
        {
            Node<t>* newNode = new Node<t>;
            newNode->data=arr[i];
            if(topIndex == 0)
            {
                topIndex=newNode;
                topIndex->link=0;
            }
            else
            {
                newNode->link=topIndex;
                topIndex=newNode;
            }
        }

    }

    return *this;


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
