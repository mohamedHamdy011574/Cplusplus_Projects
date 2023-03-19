#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

template<class t>
struct Node
{
    t data;
    Node<t>* link ;

};

template<class t>
class linkedList
{
    protected:
        Node<t>* head;
        Node<t>* tail;
        int length;
    public:
        linkedList();
        linkedList(const linkedList<t>& otherObj);

        void createLinkedList();

        bool listIsEmpty();
        bool nodeSearch(const t& dataToSearch);
        int getlength()const{ return length;}

        Node<t>* getHeadPtr()const{ return head;}
        Node<t>* getTailPtr()const{ return tail;}

        void insertInBegin(const t& newData);
        void insertInEnd(const t& newData);
        void insertInPos(const t& newData,int pos);

        void delFromBegin();
        void delFromEnd();
        void delFromPos(int pos);

        void reverseList();
        void reverseList2();


        friend ostream& operator << (ostream& output,const linkedList<t> rightObj)
        {
            Node<t>* temp=rightObj.head;
            while(temp!= 0)
            {
                 output<<temp->data;
                if(temp->link !=0){
                    output<<" -> ";
                }
                temp=temp->link;
            }
            return output;
        }

        ~linkedList();


};

template<class t>
linkedList<t>::linkedList()
{
    head= new Node<t>;
    tail= new Node<t>;
    head=tail=0;
    length=0;
}

template<class t>
linkedList<t>::linkedList(const linkedList<t>& otherObj)
{
    head= new Node<t>;
    tail= new Node<t>;

    head=otherObj.head;
    tail=otherObj.tail;
    length=otherObj.length;
}

template<class  t>
void linkedList<t>::createLinkedList()
{
    int choice=1;
    cout<<"create a linked list"<<endl<<endl;
    while(choice==1)
    {
         t Nodedata ;
         cout<<"enter the data of the node: ";
         cin>>Nodedata;
         insertInEnd(Nodedata);
         cout<<endl<<"to add new node, enter 1 , else for exit: ";
         cin>>choice;

    }
    cout<<endl<<"creation done , you have a list of "<<length<<" nodes"<<endl;

}

template<class t>
bool linkedList<t>::listIsEmpty()
{
    return (head==0);
}

template<class t>
void linkedList<t>::insertInBegin(const t& newData)
{
    Node<t>* newNode =new Node<t>;
    newNode->data=newData;
    newNode->link=0;

    if(head==0){
        head=tail=newNode;
    }
    else{
        newNode->link=head;
        head=newNode;
    }
    length++;
}

template<class t>
void linkedList<t>::insertInEnd(const t& newData)
{
    Node<t>* newNode=new Node<t>;
    newNode->data=newData;
   if(head==0)
    {
        head=tail=newNode;
    }
    else
    {
        tail->link=newNode;
        tail=newNode;
    }
    newNode->link=0;
    length++;
}

template<class t>
 void linkedList<t>::insertInPos(const t& newData,int pos)
 {
     Node<t>* newNode=new Node<t>;


     if(pos>length || pos<0)
        cout<<endl<<"sorry, position out of range "<<endl;
    else if(pos==1)
        insertInBegin(newData);
    else if(pos==length)
        {
            newNode->data=newData;
            Node<t>* tempNode = head;
            while(tempNode->link != tail)
            {
                tempNode=tempNode->link;
            }
            newNode->link = tail;
            tempNode->link=newNode;
            length++;
        }
    else
    {
        newNode->data=newData;
        Node<t>* temp = head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->link;
        }
        newNode->link=temp->link;
        temp->link=newNode;
        length++;
    }
}

template<class t>
void linkedList<t>::delFromBegin()
{

    if(head==0)
        cout<<endl<<"sorry your list is empty , no node to delete"<<endl;
    else
    {
        Node<t>* tempToDel = head;
        head=head->link;
        delete tempToDel;
        length--;
    }


}

template<class t>
void linkedList<t>::delFromEnd()
{
    if(head==0)
        cout<<endl<<"sorry your list is empty, no node to delete"<<endl;
    else
    {
        Node<t>* tempToDel = head ;

        while(tempToDel->link != tail)
        {
            tempToDel=tempToDel->link;
        }
        tail=tempToDel;
        tempToDel=tempToDel->link;
        delete tempToDel;
        tail->link=0;
        length--;

    }

}

template<class t>
void linkedList<t>::delFromPos(int pos)
{
    if(pos>length || pos<0)
        cout<<endl<<"sorry, position out of range "<<endl;
    else if(pos==1)
        delFromBegin();
    else if(pos==length)
        delFromEnd();
    else
    {
            Node<t>* tempToDel = head;
            Node<t>* previousNode = 0;

            for(int i=1;i<pos;i++)
            {
                previousNode=tempToDel;
                tempToDel=tempToDel->link;
            }
            previousNode->link=tempToDel->link;
            delete tempToDel;
            length--;
    }

}

template<class t>
bool linkedList<t>::nodeSearch(const t& dataToSearch)
{
   if(head == 0){
        cout<<endl<<"No nodes on the list to search in"<<endl;
        return false;
    }

   else if(dataToSearch == tail->data)
        return true;

   else
   {
       Node<t>* currentNode = head;
       while(currentNode != tail)
       {
           if(dataToSearch == currentNode->data)
                return true;
           currentNode = currentNode->link;
       }
   }
    return false;
}

template<class t>                            // head=100   [1/200] -> [2/300] -> [3/400] -> [4/0]    tail=400
void linkedList<t>::reverseList()           // head=100/true     head=200/true    head=300/true     head=400/false
{   if(head != 0){                         //  i=0/arr[0]=100    i=1/arr[1]=200   i=2/arr[2]=300    i=3/ break loop  arr[3]=head=400
        Node<t>* arr[length]={0};
        tail=head;
        for(int i=0; head->link != 0;i++)         // tail=100    [ 100 - 200 - 300 - 400 ]  head=400
        {                                        //      [1/..] <- [2/..] <- [3/..] <- [4/..]
            arr[i]=head;                        //  i=2 / [4/arr[2]=300]  i=1 /[3/arr[1]=200]  i=0/[2/arr[0]=100]  i=-1/ break loop
            head=head->link;                   //    tail=100   [1/0] <- [2/100] <- [3/200] <- [4/300] head=400;
        }
        arr[length-1]=head;
        Node<t>* currentNode = head;
        for(int i=length-2 ;i>=0;i--)
        {
            currentNode->link = arr[i];
            currentNode = currentNode->link;
        }

        tail->link=0;
    }
    else
        cout<<endl<<"you try to reverse an empty list, please make list first"<<endl;

}

/*template<class t>
void linkedList<t>::reverseList2()
{   if(head != 0){
        Node<t>* prevNode=0,nextNode=head;
        tail=head;
        while(nextNode!=0)
        {
            nextNode=nextNode->link;
            head->link=prevNode;
            prevNode=head;
            head=nextNode;
        }
    }
    else
        cout<<endl<<"you try to reverse an empty list, please make list first"<<endl;

}
*/
template<class t>
linkedList<t>::~linkedList()
{
        Node<t>* temp;
        while(head!=0){
            temp=head;
            head=head->link;
            delete temp;
        }

    tail=0;
    length=0;
}

#endif // LINKEDLIST_H_INCLUDED
