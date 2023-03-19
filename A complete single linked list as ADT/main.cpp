#include <iostream>
#include <iostream>
#include"list.h"
#include <bits/stdc++.h>
#include <bits/stdtr1c++.h>

using namespace std;

int main()
{
try{

    List<int>::Iterator<int> a;

    List<int> myList(1,3);

    a=myList.Begin();

    cout<<endl<<"this is my linked list: ";
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    cout<<endl<<endl;

    a=myList.Begin();

    myList.push_back(2);
    cout<<"insert \"2\"  using push_back"<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    cout<<endl;

    a=myList.Begin();
    myList.Insert(0,a);

    cout<<setw(50)<<setfill('.')<<" ";
    cout<<endl<<endl<<"insert \"0\" in the first: "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }

    myList.Insert(5,a);

    a=myList.Begin();
    cout<<endl<<"insert \"5\" in the end: "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    a=myList.Begin();

    a++;
    a++;
    myList.Insert(2,a);

    a=myList.Begin();
    cout<<endl<<"insert in a Position, ex: insert \"2\" position 3 : "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    cout<<endl;
    a=myList.Begin();

    a=myList.Erase(a);

    a=myList.Begin();
    cout<<setw(50)<<setfill('.')<<" ";
    cout<<endl<<endl<<"delete from the first: "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }


    a=myList.getTail();
    a=myList.Erase(a);
    a=myList.Begin();

    cout<<endl<<"delete from the end: "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }

    a=myList.Begin();

    a++;
    a++;
    a=myList.Erase(a);

    a=myList.Begin();
    cout<<endl<<"delete from a position , ex: position 3 : "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    cout<<endl;

    a=myList.Begin();
    a.setFirstNode(myList.getHead());
    a++;
    a++;
    --a;
    myList.Erase(a);

    a=myList.Begin();
    cout<<"delete 2nd node after jump on nodes twice using '++': to 3rd node , then use '--' to back to 2nd node: "<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    cout<<endl;
    a=myList.Begin();

    List<int> myList2(2,4);
    myList=myList2;
    a=myList.Begin();

    cout<<setw(50)<<setfill('.')<<" ";
    cout<<endl<<endl<<"copy a list in my list with different size and data"<<endl;
    while(a != myList.End())
    {
        cout<<*a;
        a++;
        if(a != myList.End())
            cout<<" -> ";
    }
    cout<<endl;

    List<int> myList3;
    myList3=myList;
    a=myList3.Begin();

    cout<<"copy my list after edit into an empty list and print this list: "<<endl;
    while(a != myList3.End())
    {
        cout<<*a;
        a++;
        if(a != myList3.End())
            cout<<" -> ";
    }
     cout<<endl;
    cout<<endl;


}
catch(const char* s)
{
    cout<<s<<endl;
}
catch(exception& s)
{
    cout<<s.what()<<endl;
}

}
