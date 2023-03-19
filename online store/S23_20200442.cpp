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
            itemPrice=0.0;
            itemQuantity=0;
            itemID=0;
        }
        Item(string name,int quantity,double price)          // parametrized constructor take 3 parameters(name,quantity,and price)of a single item and return no value
        {
            ID++;
            itemID=ID;
            itemName=name;
            itemPrice=price;
            itemQuantity=quantity;
        }
        Item(const Item &anotherItem)         // copy constructor to allow using item-1=item-2 without any errors
        {
            itemName=anotherItem.itemName;
            itemPrice=anotherItem.itemPrice;
            itemQuantity=anotherItem.itemQuantity;
            itemID=anotherItem.itemID;

        }

    // setters to the private member variables except the id

        void setname(string NAME){itemName=NAME;}
        void setquantity(int QUANTITY){itemQuantity=QUANTITY;}
        void setprice(double PRICE){itemPrice=PRICE;}

    // getters to the private member variables

        string getname()const{return itemName;}
        int getquantity()const{return itemQuantity;}
        double getprice()const{return itemPrice;}
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

		Item* getArrayOfItems( )const
		{
			Item* ptr=new Item;
			ptr=items;

			return ptr;

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
                if(items[0].itemName =="i have no name")
                    cout<<"list is empty add items please"<<endl<<endl;
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

        ~Seller()
            {
                delete []items;

            }
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
    do{
        cin>>theStoreCapacity;
        if(theStoreCapacity<=0)
            cout<<"enter the capacity again (must be greater than 0 )"<<endl;
    }while(theStoreCapacity<=0);


    Seller S1(nameOfTheSeller,Email,theStoreCapacity);

      Item* ptr2=new Item;                                     // dynamic allocation for an pointer its type is Item
    ptr2=S1.getArrayOfItems( );                // carry the return array from the function getArrayOfItems we will see its function

    cout<<endl<<endl;
   do {

        cout<<"1. Print My Info.      \n";                // the interface of the program which allow user to choose from various options
        cout<<"2. Add An Item.        \n";
        cout<<"3. Sell An Item.       \n";
        cout<<"4. Print Items.        \n";
        cout<<"5. Find An Item by ID. \n";
        cout<<"6. Exit.               \n";
        cout<<endl;
        cout<<"what do you want to do now ? choose from the list: ";
        cin>>Task;
        while(Task<1 || Task>6)                              // while loop to prevent the user from enter a number which is not in the menu
            {
                cout<<endl;
                cout<<"please enter a valid number: ";
                cin>>Task;
                cout<<endl;
            }
        cout<<endl;

        if(Task==1)                 // if Seller choose number 1 we will print him/her information
        {
            cout<<S1<<endl;
        }
        else if(Task==2)          // if Seller choose number 2 we will allow him/her to add new item
        {
            Item myitem;       // a shadow item to use >> item and don't increase the id
            cin>>myitem;
            cout<<endl;
          if(myitem.getquantity()>0){                                   //if the new item has quantity > 0 we add the item normally
            if(ptr2[0].getname()=="i have no name")                    // if the first place on the array is empty
            {
                Item realitem(myitem.getname(),myitem.getquantity(),myitem.getprice());  // we declare a real item and add it and id+=1
                    if(S1.addItem(realitem)){
                        cout<<"the item added successfully. "<<endl<<endl;
                    }
                    else{
                        cout<<"the capacity of the store is full. "<<endl<<endl ;      // if capacity is full item will not be aadded
                        }
                }

            else{                                                // if the first element is not empty (handling adding same name of item in the second time )

                for(int i=0;i<theStoreCapacity;i++)             // for loop to search in the array
                {
                    if( ptr2[i].getname()==myitem.getname()){               // we have this item before and we increase its quantity
                        if(S1.addItem(myitem)){                            // we passing the shadow item to prevent increasing the id
                            cout<<"the item added successfully. "<<endl<<endl;
                            break;                                                    // break the loop for decrease the time time
                    }
                    else{
                        cout<<"the capacity of the store is full. "<<endl<<endl;
                        break;
                        }
                    }
                    else if(ptr2[i]. getname()!= myitem. getname()){              // if the item we will add is new and we haven't it before
                        Item realitem(myitem.getname(),myitem.getquantity(),myitem.getprice()); //declare the real item and id+=1 because its parametrized object
                        if(S1.addItem(realitem)){
                            cout<<"the item added successfully. "<<endl<<endl;
                            break;
                            }
                        else{
                            cout<<"the capacity of the store is full. "<<endl<<endl;
                            break;
                                }
                            }
                        }
                    }
                }
            else
                cout<<"please enter quantity more than 0 "<<endl<<endl;
        }




        else if(Task==3)                       // if the Seller choose 3 we will allow him/her to sell any quantity of item but must be > 0
        {
                cout<<"enter the name of the item (must be the same name please take care from capital and small letters): ";
                cin>>nameOfTheItem;
                cout<<"enter the quantity of the item:";
                cin>>quantityOfTheItem;
                cout<<endl;
            if(quantityOfTheItem>0){
                if(S1.sell_item(nameOfTheItem,quantityOfTheItem))
                    cout<<quantityOfTheItem<<" from "<<nameOfTheItem<<" sold successfully. "<<endl;
                cout<<endl;
            }
            else
                cout<<"please enter quantity more than 0 "<<endl<<endl;
            }

        else if(Task==4)           // if Seller choose 4 we will print his information using >>
        {
            S1.print();
        }

        else if(Task==5)         // if Seller choose 5 we will allow him/her to search for an item using its id
        {
            cout<<"enter the id: ";
            cin>>idOfTheItem;
            cout<<endl;
            Item x;             // again using shadow item to prevent id from increase and allow us to search for specific id
            if(x==S1.FindItemID(idOfTheItem))                                             // if id is not in the list
                cout<<"sorry,there is no item with this id, please add it."<<endl<<endl;
            else
                cout<<S1.FindItemID(idOfTheItem)<<endl;
        }
        else if(Task==6)
        {
            cout<<"......GOOD BYE Mr. "<<nameOfTheSeller<<"...... "<<endl<<endl;
            exit(0);
        }

    }while(Task>=1 && Task<=6);

    delete ptr2;
}
