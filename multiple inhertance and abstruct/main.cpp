#include <iostream>

using namespace std;
class mamel
{
    public:
        mamel(){cout<<"mamel constructor"<<endl;}
        virtual void fun(){cout<<"funnn"<<endl;}
        void hey(){cout<<"hey i am mamel"<<endl;}
};
class dog: public mamel
{
    public:
        dog(){cout<<"dog constructor"<<endl;}
        void fly(){cout<<"dogs can not fly"<<endl;}
        void fun(){cout<<"fun in dog"<<endl;}


};
int main()
{
    mamel*arr[5];
    for(int i=0;i<5;i++)
    {
        if(i%2==0)
            arr[i]=new mamel;
        else
            arr[i]=new dog;

        cout<<"................................................"<<endl;

        dog* d=dynamic_cast<dog*>(arr[i]);

        if(d!=NULL)
            d->fly();
        else
            d->hey();

        cout<<"............................................."<<endl;
    }

}
