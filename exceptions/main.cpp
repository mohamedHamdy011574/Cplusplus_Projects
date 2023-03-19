#include <iostream>

using namespace std;

/* int totalDays(int days,int week)
{
    if(days<0 || days>6 || week<0)
        throw "There is something wrong";
    else
        return(7*week+days);
}*/
class Array
{
private :
    int *ptype;
    int itsSize;
public:
    class xBoundary
    {
        private:
            double value;
        public:
            xBoundary(double v)
            {
                value=v;
            }
            double getValue()const{return value;}
    };
    Array(int sizee=10):itsSize(sizee)
    {
        ptype=new int [itsSize];
        for(int i=0;i<itsSize;i++)
            ptype[i]=0;

    }
    Array(const Array& obj)
    {
        itsSize=obj.itsSize;
        ptype=new int [itsSize];
        for(int i=0;i<itsSize;i++)
            ptype[i]=obj.ptype[i];
    }



    ~Array()
    {
        delete []ptype;
    }
    Array& operator=(const Array& obj)
    {
        if(this==&obj)
            return *this;
        else
            delete[]ptype;

        itsSize=obj.itsSize;
        ptype=new int [itsSize];
        for(int i=0;i<itsSize;i++)
            ptype[i]=obj.ptype[i];

        return *this;

    }
    int& operator[](const int index)
    {
        if(index<0 || index>=itsSize)
            throw xBoundary(index);
        return ptype[index];
    }
    friend ostream& operator<<(ostream&,const Array&);
};
ostream& operator<<(ostream& os, const Array& obj)
{
    for(int i=0;i<obj.itsSize;i++)
        cout<<"[ "<< i <<" ] : "<<obj.ptype[i]<<endl;
    return os;
}
int main()
{
   /* int days;
    try
    {
        days=totalDays(7,2);
        cout<<"total days ="<<days<<endl;          // no invoking if throw is came from peravious
    }
    catch(const char* msg)                       // catch(...) catch every thing but we can not know whats wrong
    {
        cout<<"error occur: "<<msg<<endl;
    }
    cout << "done"<<endl; */

    Array intArray(20);
    try
    {
        for(int i=0;i<100;i++)
        {
            intArray[i]=i;
            cout<<"intArray[ "<<i<<" ] okay..."<<endl;
        }
    }
    catch(Array::xBoundary m )
    {
        cout<<"this value is wrong: "<<m.getValue()<<endl;

    }
    cout<<"done....................."<<endl;


}
