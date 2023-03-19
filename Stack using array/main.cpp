#include <iostream>
#include<bits/stdc++.h>
#include "arrayStack.h"
#define El7mdllah
using namespace std;

int main()
{
                El7mdllah

    myStack<int> mstack(5);
    mstack.push(1); cout<<mstack.mySize()<<endl;
    mstack.push(2); cout<<mstack.mySize()<<endl;
    mstack.push(3); cout<<mstack.mySize()<<endl;
    mstack.push(4); cout<<mstack.mySize()<<endl;
    mstack.push(5); cout<<mstack.mySize()<<endl;
    mstack.push(6); cout<<mstack.mySize()<<endl;
    cout<<mstack<<endl;

    mstack.pop();
    mstack.pop();
    mstack.pop();

    cout<<mstack<<endl;
    cout<<"my top element: "<<mstack.top()<<endl;


    myStack<int> mstack2=mstack;
    mstack2.pop();
    cout<<mstack2;
    cout<<mstack;
    mstack2.pop();
    try{
    cout<<mstack2.top();
    }
    catch(const char* s)
    {
        cout<<s;
    }
    mstack2.pop();

    return 0;
}
