#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

class contactInfo{

private:
    char *name;
    char *phone;

    void setname(char*a)
    {
        name=new char [strlen(a)+1];
        strcpy(name,a);
    }
    void setphone(char*p)
    {
        phone=new char [strlen(p)+1];
        strcpy(phone,p);
    }
public:

    contactInfo(char*a,char*p)
    {
        setname(a);
        setphone(p);
    }
    ~contactInfo()
    {
        delete []name;
        delete []phone;
    }
    const char *getname()const
    {
        return name;
    }
    const char *getphone()const
    {
        return phone;
    }


};
int main()
{
    string Name,Phone;
    cout<<"enter your name \n";
    cin>>Name;
    cout<<"enter your phone number \n";
    cin>>Phone;

    char*Nm=new char[Name.size()+1];
    char*ph=new char[Phone.size()+1];

    for(int i=0;i<Name.size();i++)
        Nm[i]=Name[i];
    for(int i=0;i<Phone.size();i++)
        ph[i]=Phone[i];

    contactInfo obj(Nm,ph);
    cout<<"Your name is "<<obj.getname()<<endl;
    cout<<"Your phone is "<<obj.getphone()<<endl;

    delete [] Nm;
    delete [] ph;

    return 0;
}
