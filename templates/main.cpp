#include <iostream>
#include<string>
using namespace std;

template<class t>

class myArray
{
    protected:
        t *arr;
        int sizee;
    public:
        myArray(int s)
        {
            sizee=s;
            arr=new t[sizee];
        }
        myArray(const myArray& right)
        {
            sizee=right.sizee;
            delete []arr;
            arr=new t[sizee];
            for(int i=0;i<sizee;i++)
                arr[i]=right.arr[i];
        }
        t& operator[](const int num)
        {
            return arr[num];
        }

        ~myArray(){delete[]arr;}

};

template<class t>

class searchableArray:public myArray<t>
{
    public:
        searchableArray(int s):myArray<t>::myArray(s){};
        int findIndexOfElem(t elem)
        {
            int i;
            for( i=0;i<myArray<t>::sizee;i++)
            {
                if(elem==myArray<t>::arr[i])
                    return i;
            }
            if(i==myArray<t>::sizee)
            {
                cout<<"we did not find these element" <<endl;
                return -1;
            }

        }
        t& findElementAtIndex(int index)
        {
            if(index>=0 && index<myArray<t>::sizee){
                for(int i=0;i<myArray<t>::sizee;i++)
                {
                    if(index==i)
                        return myArray<t>::arr[i];
                }
            }
            else
                cout<<"wrong index"<<endl;
        }


};
template<class t>

class resizeableArray:public myArray<t>
{
    public:
        resizeableArray(int s):myArray<t>::myArray(s){}
        void appendElement(t elem)
        {
            t*temp=new t[myArray<t>::sizee];
            for(int i=0;i<myArray<t>::sizee;i++)
                temp[i]=myArray<t>::arr[i];
            delete []myArray<t>::arr;
            myArray<t>::sizee=myArray<t>::sizee+1;
           myArray<t>::arr=new t[myArray<t>::sizee];
            for(int i=0;i<myArray<t>::sizee;i++)
            {
                if(i!=myArray<t>::sizee-1)
                    myArray<t>::arr[i]=temp[i];
                else
                    myArray<t>::arr[i]=elem;
            }
        }


};
int main()
{
    searchableArray<string> obj1(5);

    string s;
    for(int i=0;i<5;i++)
    {
        cin>>s;
        obj1[i]=s;
    }

    for(int i=0;i<5;i++)
        cout<<obj1[i]<<" ";
    cout<<endl;

    cout<<obj1.findElementAtIndex(2)<<endl;
    cout<<obj1.findIndexOfElem(s)<<endl;

    resizeableArray <int> obj(5);
    int num;
    for(int i=0;i<5;i++)
    {
        cin>>num;
        obj[i]=num;
    }
    int elem;
    cout<<"enter the element you want to add";
    cin>>elem;
    obj.appendElement(elem);
    for(int i=0;i<6;i++)
    {
        cout<<obj[i]<<" ";
    }
}

