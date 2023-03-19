#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double calc_taxValue (double , double );

int main()
{
    string ARR_ProductName_ProductCode[1000][2],answer=" ",code,ARR_Name[1000][1];
    int NumberOfProductsInMarket,NumberOfProductsInOrder,quantity,K=1;
    double ARR_ProductPrice_ProductTax[1000][2],ARR_Information[1000][5],sum=0,totalSum=0;

    cout<<"enter the Number of products in the market :\n";
    cout<<"- ";
    cin>>NumberOfProductsInMarket;
    cin.ignore();

    for(int i=0 ; i<NumberOfProductsInMarket ; i++)
    {
        cout<<"please enter product "<<i+1<<" name,code,price and tax :\n" ;
        cout<<" Name : ";
        getline(cin,ARR_ProductName_ProductCode [i][0]);
        cout<<" Code : ";
        getline(cin,ARR_ProductName_ProductCode [i][1]);

        cout<<" Price : ";
        cin>>ARR_ProductPrice_ProductTax [i][0];
        cout<<" Tax : ";
        cin>>ARR_ProductPrice_ProductTax [i][1];
        cin.ignore();

    }
    cout<<"Now we are ready to accept any order \n";

    int x=0;
    do
    {
        sum=0;
        cout<<" please enter the number of products in the order number "<<K<<endl;
        cin>>NumberOfProductsInOrder;
        cin.ignore();

        for(int i=0 ; i<NumberOfProductsInOrder ; i++)
        {
            cout<<"please enter product code and quantity \n";
            cout<<"Code : ";
            getline(cin,code);
            cout<<"Quantity : ";
            cin>>quantity;
            cin.ignore();
            for(int j=0;j<NumberOfProductsInMarket;j++){
                if(code == ARR_ProductName_ProductCode[j][1])
                {
                    ARR_Name[x][0]=ARR_ProductName_ProductCode[j][0];
                    ARR_Information[x][0]=ARR_ProductPrice_ProductTax[j][0];
                    ARR_Information[x][1]=calc_taxValue(ARR_ProductPrice_ProductTax[j][0],ARR_ProductPrice_ProductTax[j][1]);
                    ARR_Information[x][2]=ARR_Information[x][0] + ARR_Information[x][1];
                    ARR_Information[x][3]=quantity;
                    ARR_Information[x][4]=ARR_Information[x][2] * ARR_Information[x][3];
                    x++;
                    break;

                }
            }
        }

        cout<<setw(18)<<"Product name"<<setw(18)<<"price"<<setw(18)<<"tax"<<setw(18)<<"final price"<<setw(18)<<"quantity"<<setw(18)<<"total price"<<endl<<endl;
        for(int i=0;i<NumberOfProductsInOrder;i++){
            cout<<setw(18)<<ARR_Name[i][0];
            cout<<setw(18)<<ARR_Information[i][0];
            cout<<setw(18)<<ARR_Information[i][1];
            cout<<setw(18)<<ARR_Information[i][2];
            cout<<setw(18)<<ARR_Information[i][3];
            cout<<setw(18)<<ARR_Information[i][4];
            sum+=ARR_Information[i][4];
            cout<<endl;
        }
        cout<<"________"<<endl;
        cout<<"total amount : "<<sum <<endl;
        cout<<"________"<<endl;


        cout<<"Do you want to make another order ? Yes or No \n";
        cin>> answer;
        totalSum+=sum;
        K++;


    }while(answer == "Yes" || answer == "yes");

    cout<<endl<<"Number of orders : "<<K-1<<endl;;
    cout<<"total amount of all orders : "<<totalSum<<endl;
    cout<<"Good Bye "<<"^_^";

}
double calc_taxValue(double price , double tax)
{
    double tax_value = price *(tax/100);
    return tax_value;
}
