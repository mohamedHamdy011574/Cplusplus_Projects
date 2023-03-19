#ifndef ARRAYSTACK_H_INCLUDED
#define ARRAYSTACK_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class t>
class myStack
{
    private:
        t* arr;
        int maxSize;
        int topIndex;
    public:
        myStack();
        myStack(int);
        myStack(const myStack<t>&);

        void push(const t& data);
        void pop();
        t top()const;
        int mySize()const;
        bool isEmpty()const;
        bool isFull()const;

        myStack<t> operator=(const myStack<t>&);

        template<class t1>
        friend ostream& operator<<(ostream& os,const myStack<t1>& rightObj)
        {
            for(int i=0;i<=rightObj.topIndex;i++)
            {
                os<<rightObj.arr[i]<<" ";
            }
            cout<<endl;
            return os;
        }
        ~myStack();


};

template<class t>
myStack<t>::myStack()
{
    arr=new t[50];
    maxSize=50;
    topIndex=-1;

}

template<class t>
myStack<t>::myStack(int stackSize)
{
    arr=new t[stackSize];
    maxSize=stackSize;
    topIndex=-1;
}

template<class t>
myStack<t>::myStack(const myStack<t>& otherObj)
{
    maxSize=otherObj.maxSize;
    topIndex=otherObj.topIndex;

    arr=new t[maxSize];

    for(int i=0;i<=topIndex;i++)
    {
            arr[i]=otherObj.arr[i];
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
        topIndex++;
        arr[topIndex]=data;
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
        topIndex--;
    }

}

template<class t>
t myStack<t>::top()const
{
    if(isEmpty())
        throw("sorry, your stuck is empty \n");

    else
        return arr[topIndex];
}

template<class t>
int myStack<t>::mySize()const
{
    return topIndex+1;
}

template<class t>
bool myStack<t>::isEmpty()const
{
    return (topIndex == -1);
}

template<class t>
bool myStack<t>::isFull()const
{
    return (topIndex == maxSize-1);
}
template<class t>
myStack<t> myStack<t>::operator=(const myStack<t>& rightObj)
{
    if(&rightObj != this)
    {
        delete []arr;

        maxSize=rightObj.maxSize;
        topIndex=rightObj.topIndex;

        arr = new t[maxSize];
    }
    return *this;


}
template<class t>
myStack<t>::~myStack()
{
    delete []arr;

}

#endif // ARRAYSTACK_H_INCLUDED
