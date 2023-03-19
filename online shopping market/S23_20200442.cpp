
#include <iostream>
#include <string>


using namespace std;

class Item
{
    private:
        static int ID;
        int itemID;
        string itemName;
        int itemQuantity;
        double itemPrice;

    public:
        Item()                 // default constructor take no parameter and return no value
        {
            itemName="i have no name";
            itemPrice=0;
            itemQuantity=0;
            itemID=0;
        }
        Item(string name,int quantity,int price)          // parametrized constructor take 3 parameters(name,quantity,and price)of a single item and return no value
        {
            ID++;
            itemID=ID;
            itemName=name;
            itemPrice=price;
            itemQuantity=quantity;
        }
        Item(const Item &anotherItem)         // copy constructor to allow using " Item item-1(item-2) " without any errors
        {
            itemName=anotherItem.itemName;
            itemPrice=anotherItem.itemPrice;
            itemQuantity=anotherItem.itemQuantity;
            itemID=anotherItem.itemID;
            ID=anotherItem.ID;
        }

    // setters to the private member variables except the id

        void setname(string NAME){itemName=NAME;}
        void setquantity(int QUANTITY){itemQuantity=QUANTITY;}
        void setprice(int PRICE){itemPrice=PRICE;}

    // getters to the private member variables

        string getname()const{return itemName;}
        int getquantity()const{return itemQuantity;}
        int getprice()const{return itemPrice;}
        int getid()const{return itemID;}

    // operator overloading functions +=,-=,==,<< and >> operators

        bool operator==(const Item &otherItem)          // operator == to check if name of item-1 = to name of item-2 or not
        {
            if(itemName==otherItem.itemName)
                return true;
            else
                return false;
        }

        Item operator+=(const Item &item2)           // operator += to increment the quantity of item-1 by the quantity of the parameter item
        {
            itemQuantity+=item2.itemQuantity;
            return *this;
        }

        Item operator+=(int number)                 // if we take number as parameter
        {
            itemQuantity+=number;
            return *this;
        }

        Item operator-=(const Item &item2)      //operator -= to decrement the quantity of item-1 by the quantity of item-2
        {
            itemQuantity-=item2.itemQuantity;
            return *this;
        }

        Item operator-=(int number)             // if we take a number as a parameter
        {
            itemQuantity-=number;
            return *this;
        }


        friend ostream& operator<<(ostream&,const Item&); // operators >> and << to allow the program to take items from user
        friend istream& operator>>(istream&,Item&); // and print items details to the user and they must be friends

        friend class Seller;


};int Item::ID=0;

    ostream& operator<<(ostream& output, const Item& rightObject)   // operator << which print the details of the item
    {
        output<<"Item's ID: "<<rightObject.itemID<<endl;
        output<<"Item's name: "<<rightObject.itemName<<endl;
        output<<"Item's price: "<<rightObject.itemPrice<<endl;
        output<<"Item's quantity: "<<rightObject.itemQuantity<<endl;

        return output;
    }

    istream& operator>>(istream& input, Item&  rightObject)        // operator >> which take the details of the item
    {
        cout<<"enter name,price and quantity of the item separating by space \n\n";
        input>>rightObject.itemName>>rightObject.itemPrice>>rightObject.itemQuantity;

        return input;
    }

class Seller
{
    private:
        string sellerName,sellerEmail;
        Item* items;
        int maxitems;
    public:
        Seller(string name,string mail,int maxNumberOfItems) // parametrized constructor take 3 parameters: name,mail of seller
        {                                                    // and the capacity(maxNumberOfItems) of the store
            sellerName=name;
            sellerEmail=mail;
            maxitems=maxNumberOfItems;
            items=new Item[maxitems];                // dynamic allocation to the array which carry all items of the stor
        }

        bool addItem(const Item&item)          // member function addItem which add a new item if the item is new one
        {                                      // and if not it increment the quantity of the old item with the same name
            int i;                            // and if there is no space in the store it return false
            for(i=0;i<maxitems;i++)
            {
                if(items[i]==item)
                {
                    items[i]+=item;
                    return true;
                }
            }
            for(i=0;i<maxitems;i++)
            {
                if(items[i].itemID==0)
                {

                    items[i]=item;
                    return true;
                }
            }
            if(i==maxitems)
                return false;

        }

        bool sell_item(string ItemName,int ItemQuantity)    //member function sell_item which sell an item from the store
        {                                                  // and decrement its quantity by the the quantity which has been sold
            int i;
            for(i=0;i<maxitems;i++)
            {
                if(items[i].itemName==ItemName)
                {
                    if(items[i].itemQuantity >= ItemQuantity)
                    {
                        items[i]-=ItemQuantity;
                        return true;
                    }
                    else{
                        cout<<"there is only "<<items[i].itemQuantity<<" left for this item \n";
                        return false;
                    }
                }
            }
            if(i==maxitems)
            {
                cout<<"sorry, there is no item has the name "<<ItemName<<" please add it to the stores items "<<endl;
                return false;
            }

        }

        void print()                             // member function print which print all the details about specific item
        {

            for(int i=0;i<maxitems;i++)
            {
                if(items[i].itemID==0)
                    break;
                else
                    cout<<items[i]<<endl;
            }
        }

        Item FindItemID(int ItemId)            // member function FindItemID which search for an id and return the item
        {                                       // which has this id
            int i;
            for(i=0;i<maxitems;i++)
            {
                if(items[i].itemID==ItemId)
                    return items[i];
            }
            Item x;
            if(i==maxitems){
                return x;
            }


        }

        friend ostream& operator<<(ostream&,Seller&);   //operator << to print the information of the seller



};

    ostream& operator<<(ostream& Output,Seller& theSeller)
    {
        Output<<"The name of the seller: "<<theSeller.sellerName<<endl;
        Output<<"The mail of the seller: "<<theSeller.sellerEmail<<endl;
        Output<<"The capacity of the store: "<<theSeller.maxitems<<endl;

        return Output;
    }
int main()
{
    string nameOfTheSeller,Email,nameOfTheItem;
    int theStoreCapacity,Task,quantityOfTheItem,idOfTheItem;


    cout<<"please enter your name and email"<<endl;
    cout<<"Name: ";
    getline(cin,nameOfTheSeller);
    cout<<"Email: ";
    getline(cin,Email);
    cout<<endl;
    cout<<"now enter the capacity of your store: ";
    cin>>theStoreCapacity;


    Seller S1(nameOfTheSeller,Email,theStoreCapacity);

    cout<<endl<<endl;
   do {

        cout<<"1. Print My Info.      \n";
        cout<<"2. Add An Item.        \n";
        cout<<"3. Sell An Item.       \n";
        cout<<"4. Print Items.        \n";
        cout<<"5. Find An Item by ID. \n";
        cout<<"6. Exit.               \n";
        cout<<endl;
        cout<<"what do you want to do now ? choose from the list: ";
        cin>>Task;
        while(Task<1 || Task>6)              // while loop to allow the user to enter the number of the task again if he/she enter an invalid one
            {
                cout<<endl;
                cout<<"please enter a valid number: ";
                cin>>Task;
                cout<<endl;
            }
        cout<<endl;

        if(Task==1)
        {
            cout<<S1<<endl;
        }
        else if(Task==2)
        {
            Item myitem;
            cin>>myitem;
            cout<<endl;
            Item realitem(myitem.getname(),myitem.getquantity(),myitem.getprice());
            if(S1.addItem(realitem) && myitem.getquantity()>0)         //condition statement to show that the item has been added successfully
                cout<<"the item added successfully. "<<endl<<endl;
            else
                cout<<"the capacity of the store is full. "<<endl<<endl;     // if capacity is full
        }
        else if(Task==3)
        {
                cout<<"enter the name of the item: ";
                cin>>nameOfTheItem;
                cout<<"enter the quantity of the item:";
                cin>>quantityOfTheItem;
                cout<<endl;
                if(S1.sell_item(nameOfTheItem,quantityOfTheItem))   //condition statement to print message to show that the item has been sold successfully
                    cout<<quantityOfTheItem<<" from "<<nameOfTheItem<<" sold successfully. "<<endl;
                cout<<endl;
        }
        else if(Task==4)
        {
            S1.print();
        }
        else if(Task==5)
        {
            cout<<"enter the id: ";
            cin>>idOfTheItem;
            cout<<endl;
            Item x;                                            // a temp item help to find if the id which the user wrote is in the list of items or not
            if(x==S1.FindItemID(idOfTheItem))                 // if the return is also a temp from type Item so id is not found
                cout<<"sorry,there is no item with this id, please add it."<<endl<<endl;
            else
                cout<<S1.FindItemID(idOfTheItem)<<endl;       //else it is found and we print the details of this item
        }
        else if(Task==6)
        {
            cout<<".....< Thank you for using my program >....."<<endl;
            exit(0);
        }

    }while(Task>=1 && Task<=6);

}
