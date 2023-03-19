#include <iostream>

using namespace std;

                                // the code with the bonus requirements

class PersonData
    {
        string lastName;
        string firstName;
        string address;
        string city;
        string phone;
public:
 PersonData(string ln=" ",string fn=" ",string a=" ",string c=" ", string p=" ")
    {
     setPData(ln,fn,a,c,p);
     }
 void printPerson()
    {
        cout<<"First Name: "<<firstName<<endl;
        cout<<"Last Name: "<<lastName<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"City: "<<city<<endl;
        cout<<"Phone: "<<phone<<endl;
    }
 void setPData(string ln,string fn,string a,string c, string p)
    {
        lastName=ln;
        firstName=fn;
        address=a;
        city=c;
        phone=p;
    }
};

class CustomerData:public PersonData
{
    private:
        int customerNumber;
        bool mailingList;
    public:
        CustomerData();
        CustomerData ( string, string , string ,string , string , int , bool);
        void printCustomer();
        void setCustData(string, string , string ,string , string , int , bool);
};
    CustomerData::CustomerData():PersonData()
    {
        customerNumber=0;
        mailingList=false;
    }
    CustomerData::CustomerData(string lastName,string firstName, string city ,string address, string phone, int customerNumber,bool mailingList):PersonData(lastName,firstName,city,address,phone)
    {
        setPData(lastName,firstName,address,city,phone);
        this->customerNumber=customerNumber;
        this->mailingList=mailingList;
    }
    void CustomerData::printCustomer()
    {
        printPerson();
        cout<<"Customer Number: "<<customerNumber<<endl<<endl;
    }
    void CustomerData::setCustData(string lastName,string firstName, string city ,string address, string phone, int customerNumber,bool mailingList)
    {
        setPData(lastName,firstName,address,city,phone);
        this->customerNumber=customerNumber;
        this->mailingList=mailingList;
    }
int main()
{
    string last_name,first_name,customerCity,customerAddress,customerPhone;
    int TheNumberOfCustomers;
    cout<<"please enter the number of the customers: ";
    cin>>TheNumberOfCustomers;
    cout<<endl;

         // bonus using array of parametrized constructor

    CustomerData **ListOfCustomer=new CustomerData*[TheNumberOfCustomers];

    for(int i=0;i<TheNumberOfCustomers;i++)
    {
        cout<<"please enter the first name of the customer: ";
        cin>>first_name;
        cout<<"please enter the last name of the customer: ";
        cin>>last_name;
        cin.ignore();
        cout<<"please enter the city: ";
        getline(cin,customerCity);
        cout<<"please enter the address of the customer: ";
        getline(cin,customerAddress);
        cout<<"please enter the phone of the customer: ";
        getline(cin,customerPhone);
        cout<<endl;

        *(ListOfCustomer+i)=new CustomerData(last_name,first_name,customerCity,customerAddress,customerPhone,i+1,false);
    }
    cout<<"there is the list of customers: "<<endl<<endl;
    for(int i=0;i<TheNumberOfCustomers;i++)
    {
        ListOfCustomer[i]->printCustomer();
    }

    for(int i=0;i<TheNumberOfCustomers;i++)
        delete ListOfCustomer[i];

    delete []ListOfCustomer;
}
