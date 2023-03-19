#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>
#include <bits/stdtr1c++.h>


using namespace std;

// a new data type called Node include [data,pointer to next node]
template<class t>
struct Node
{
    t data;
    Node<t>* link ;
};

// a template class called list which represent a linked list as ADT ( abstracted data type )
template<class t>
class List
{
    protected:
        Node<t>* head;                       // pointer point to the first node in the list
        Node<t>* tail;                      // pointer point to the last node in the list
        Node<t>* dumyNode;                 // pointer point to the dumyNode in my list
        int length;                       // length to store the length of the list (number of nodes in the list)
    public:

        // a template inline class called iterator we will use it to jump between the node of the linked list from right to left
        template<class t1>
         class Iterator
        {
            private:
                // a pointer to my current node that i stand on it in my list
                Node<t1>* currentNode;

                Node<t1>* firstNode;          // pointer to star the address of first node in my list
            public:

               // make a class 'list' friend to class 'iterator'
               //to allow class 'list'access the private member variables inside class 'iterator'
               friend class List<t1>;

                //default constructor
                Iterator()
                {
                    currentNode=0;            // make pointer point to null (initialize it to 0)
                    firstNode=0;
                }

                //parameterized constructor that take a pointer to a node as an argument
                Iterator(Node<t1>* ptr)
                {
                    currentNode=ptr;
                }

                //function to store the head of the list to help me to get previous node in single linked list
                void setFirstNode(Node<t1>* ptr)
                {
                    firstNode=ptr;
                }
                //operator overloading to '*' to make it return the data inside the node that currentNode pointer points to it
                t1& operator*()
                {
                    if(currentNode->link != 0)
                        return currentNode->data;

                    // if we try to get a data from outside the list so throw exception
                    else
                        throw "sorry, cannot access data outside your list nodes";
                }

                //operator overloading to '++' operator to travel from node to the next node  , prefix
                Iterator<t1> operator++()
                {
                    if(currentNode->link != 0){
                        currentNode=currentNode->link;
                        return *this;
                    }
                    else
                        throw "iterator break the length of the list";
                }

                // postfix overloading
                Iterator<t1> operator++(int)
                {
                    if(currentNode->link != 0){
                        Iterator temp = *this;
                        currentNode=currentNode->link;
                        return temp;
                    }
                    else
                        throw "iterator break the length of the list";
                }

                //operator overloading for '--' operator as prefix
                Iterator<t1> operator--()
                {
                    if(currentNode == firstNode)
                        throw("iterator break the list , it points to first node and no previous node");
                    else
                        {
                            Node<t1>* previousNode = 0;
                            while(firstNode != currentNode)
                            {
                                previousNode=firstNode;
                                firstNode=firstNode->link;
                            }
                            currentNode=previousNode;
                            return *this;
                        }
                }

                // operator overloading for '==' to check if the currentNode is the same node the iterator.currentNode point to
                bool operator == (const Iterator<t1>& it)
                {
                    return(currentNode==it.currentNode);
                }

                //operator overloading to '!='
                bool operator != (const Iterator<t1>& it)
                {
                    return(currentNode!=it.currentNode);
                }

        };


        //constructors of the class
        List();
        List(t value, int initialSize);

        // function to check if the list is empty
        bool listIsEmpty();
        //getter function to return the size of the list
        int getlength()const{ return length;}
        Node<t>* getHead()const{return head;}

        // functions that return a iterator point to some node in the list
        Iterator<t> Begin()const;
        Iterator<t> End()const;
        Iterator<t> getTail()const;

        // 2 functions to add nodes in the list one take the value and add node in the end (push_back) and one
        // insert in the position the iterator point in (insert)
        void push_back(t value);
        void Insert(t value, Iterator<t>& pos);

        // function to delete node from the list depend on the iterator points to what
        Iterator<t> Erase(Iterator<t>& pos);

        //operator overloading to '=' operator
        List<t>& operator =(const List<t>& otherList);

        // destructor to free the memory by delete all nodes in the list at the end of program
        ~List();





};

template<class t>
List<t>::List()
{
    dumyNode=new Node<t>;
    head=tail=dumyNode;
    dumyNode->link=0;

      length=0;
}

template<class t>
List<t>::List(t value,int initialSize)
{

        head= new Node<t>;
        tail= new Node<t>;
        dumyNode=new Node<t>;
        head=tail=dumyNode;

        dumyNode->link=0;

        length=initialSize;

        for(int i=0;i<length;i++){
            Node<t>* newNode=new Node<t>;

            newNode->data=value;


          //  cout<<" new:"<<newNode<<", dumy:"<<dumyNode<<", head:"<<head<<"\---/ ";
            if(head==dumyNode){
                head=tail=newNode;
            }
            else
            {
                tail->link=newNode;
                tail=newNode;
            }

            newNode->link=dumyNode;
        }

}
template<class t>
List<t>::Iterator<t> List<t>::Begin()const
{
    Iterator<t> it(head);
    return it;
}
template<class t>
 List<t>::Iterator<t> List<t>::End()const
{
    Iterator<t> it(tail->link);
    return it;
}
template<class t>
 List<t>::Iterator<t> List<t>::getTail()const
{
    Iterator<t> it(tail);
    return it;
}




template<class t>
bool List<t>::listIsEmpty()
{
    return (head==dumyNode);
}

template<class t>
void List<t>::push_back(t value)
{
    Node<t>* newNode = new Node<t>;
    newNode->data=value;
    newNode->link=0;



    if(head==dumyNode)
    {
        head=tail=newNode;
    }
    else
    {
        tail->link=newNode;
        tail=newNode;
    }
    newNode->link=dumyNode;
    length++;

}

template<class t>
void List<t>::Insert(t value , List<t>::Iterator<t>& pos)
{

    Node<t>* newNode = new Node<t>;
    newNode->data=value;
    newNode->link=0;



    if(head==dumyNode)
    {
        head=tail=pos.currentNode=newNode;
        newNode->link=dumyNode;
    }
    else if(head==pos.currentNode)
    {
        newNode->link=head;
        head=pos.currentNode=newNode;
    }
    else if(tail == pos.currentNode)
    {
        Node<t>* temp=head;
        while(temp->link != tail)
        {
            temp=temp->link;
        }
        newNode->link=tail;
        temp->link=pos.currentNode=tail=newNode;
        tail->link=pos.currentNode->link=dumyNode;

    }
    else if(pos.currentNode == dumyNode)
    {
        newNode->link = dumyNode;
        tail->link=newNode;
        tail=newNode;
        pos.currentNode=newNode;
    }
    else
    {
        Node<t>* temp=head;
        while(temp->link != pos.currentNode)
        {
            temp=temp->link;
        }
        newNode->link=temp->link;
        temp->link=pos.currentNode=newNode;
    }
    length++;
}

template<class t>
List<t>::Iterator<t> List<t>::Erase(List<t>::Iterator<t>& pos)
{
    if(head == dumyNode || pos.currentNode==dumyNode)
    {
        throw " you try to delete from empty list , make a list first";
    }
    else if(head==pos.currentNode)
    {
        Node<t>* tempToDel=head;

        if(head->link==dumyNode){
                head=tail=pos.currentNode=dumyNode;
        }
        else{
            head=pos.currentNode=head->link;
        }
        delete tempToDel;
    }
    else if(tail==pos.currentNode )
    {
        Node<t>* temp=head;
        while(temp->link != tail)
        {
            temp=temp->link;
        }
        tail=pos.currentNode=temp;
        temp=temp->link;
        delete temp;
        tail->link=dumyNode;

    }
    else
    {
        Node<t>* previousNode=head;
        while(previousNode->link != pos.currentNode)
        {
            previousNode=previousNode->link;
        }
        Node<t>* nextNode=previousNode->link->link;
        Node<t>* currentNode=previousNode->link;
        previousNode->link=pos.currentNode=nextNode;
        delete currentNode;
    }
    length--;
    return pos;


}

template<class t>
List<t>& List<t>:: operator =(const List<t>& otherList)
{
    if(&otherList != this || head != dumyNode)
    {
        Node<t>* temp;
        while(head!=dumyNode){
            temp=head;
            head=head->link;
            delete temp;
        }

        tail=dumyNode;
        length=0;

        length=otherList.getlength();

        Node<t>* tempNode=otherList.head;

        while(tempNode != otherList.dumyNode)
        {

                Node<t>* newNode=new Node<t>;
                newNode->data=tempNode->data;

                if(otherList.head == otherList.dumyNode)
                {
                    head=tail=dumyNode;
                    length=0;
                }
                else if(head==dumyNode)
                {

                    newNode->link=dumyNode;
                    head=tail=newNode;
                }
                else
                {

                    tail->link=newNode;
                    tail=newNode;
                    tail->link=dumyNode;

                }
                tempNode=tempNode->link;
            }
        }

        return *this;


}

template<class t>
List<t>::~List()
{
        Node<t>* temp;
        while(head!=dumyNode){
            temp=head;
            head=head->link;
            delete temp;
        }

    tail=dumyNode;
    length=0;
}
#endif // LIST_H_INCLUDED
