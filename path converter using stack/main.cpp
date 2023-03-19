#include <iostream>
#include<string>
#include"linkedlistStack.h"

using namespace std;


string simplifyPath( const string& pth)
{
    myStack<string> mySt;
    string myRes;
    int sizee=pth.size();
    for(int i=0;i<sizee;i++)
    {

        if(pth[i]=='/')
            continue;

        string temp;

        while(i<sizee && pth[i]!='/')
            {
                temp+=pth[i];
                i+=1;
            }
            if(temp==".")
                continue;
            else if(temp == "..")
            {
                if(!mySt.isEmpty())
                    mySt.pop();
            }
            else
            {
                mySt.push(temp);
            }
    }
        while(!mySt.isEmpty()){
            myRes="/"+mySt.top()+myRes;
            mySt.pop();
        }
        if(myRes.size()==0)
            return "/";


        return myRes;

}

int main()
{

string absPath="/home/";
string concPath = simplifyPath(absPath);

cout<<"absPath = "<<absPath<<" \t";;
cout<<"concPath= "<<concPath;
cout<<endl;

absPath="/a//b/../../c/";

concPath = simplifyPath(absPath);

cout<<"absPath = "<<absPath<<" \t";
cout<<"concPath= "<<concPath;
cout<<endl;

absPath="/a//b/../../";

concPath = simplifyPath(absPath);

cout<<"absPath = "<<absPath<<" \t ";
cout<<"concPath= "<<concPath;
cout<<endl;

absPath="/file//myProject/.//cpp/";
concPath = simplifyPath(absPath);

cout<<"absPath = "<<absPath<<" \t ";
cout<<"concPath= "<<concPath;
cout<<endl;

    return 0;
}
