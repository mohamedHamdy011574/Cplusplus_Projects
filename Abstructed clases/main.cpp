#include <iostream>

using namespace std;

class shape
{
public:
    shape(){}
    virtual long getarea()=0;
    virtual long getprem()=0;
    virtual void draw()=0;
};
long getarea()
{
    cout<<"i have area"<<endl;
    return -1;
}

long getprem()
{
    cout<<"i have prem"<<endl;
    return -1;
}

void draw()
{
    cout<<"i have a shape"<<endl;
}

class rectangle: public shape
{
    protected:
        float s1,s2;
    public:
        rectangle(float l,float w)
        {
            s1=l;
            s2=w;
        }
        virtual long getarea()
        {
            return s1*s2;
        }
        virtual long getprem()
        {
            return (s1+s2)*2;
        }
        virtual void draw()
        {
            for(int i=0;i<s1;i++)
            {
                for(int j=0;j<s2;j++)
                    cout<<"*"<<" ";
                cout<<endl;
            }
        }
};

class square: public rectangle
{
        public:
        square(float side):rectangle(side,side){}
        virtual long getarea()
        {
            return s1*s1;
        }
        virtual long getprem()
        {
            return 4*s1;
        }
        virtual void draw()
        {
            for(int i=0;i<s1;i++)
            {
                for(int j=0;j<s2;j++)
                    cout<<"*"<<" ";
                cout<<endl;
            }
        }

};
int main()
{
    rectangle s1(5,6);
    s1.draw();
    cout<<endl;
    square s2(5);
    s2.draw();
    cout<<endl;

}
