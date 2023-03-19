#include"BigInt.h"
#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main()
{
     string n1,n2;
    try{
        cout<<"test case # 1:"<<endl;
        BigInt num1("123456789012345678901234567890");
        BigInt num2("113456789011345678901134567890");
        BigInt num3=num1+num2;
        cout<<setw(21)<<"num1 = "<<num1<<endl;
        cout<<setw(21)<<"num2 = "<<num2<<endl;
        cout<<setw(28)<<"num1 + num2 = "<<num3<<endl<<endl;

        cout<<"test case # 2 :"<<endl;
        BigInt num4("-00123456789");
        BigInt num5("0012345678");
        BigInt num6=num4+num5;
        cout<<setw(21)<<"num4 = "<<num4<<endl;
        cout<<setw(21)<<"num5 = "<<num5<<endl;
        cout<<setw(28)<<"num4 + num5 = "<<num6<<endl;

        cout<<"test case # 3 :"<<endl;
        BigInt num7("-1500");
        BigInt num8("-02000");
        BigInt num9=num7+num8;
        cout<<setw(21)<<"num7 = "<<num7<<endl;
        cout<<setw(21)<<"num8 = "<<num8<<endl;
        cout<<setw(28)<<"num7 + num8 = "<<num9<<endl;


        cout<<"test case # 4:"<<endl;
        BigInt num10("1555555666677778880");
        BigInt num11("-000001664647646766620");
        BigInt num12=num10+num11;
        cout<<setw(21)<<"num10 = "<<num10<<endl;
        cout<<setw(21)<<"num11 = "<<num11<<endl;
        cout<<setw(29)<<"num10 + num11 = "<<num12<<endl<<endl;

        cout<<"test case # 5:"<<endl;
        BigInt num13("1234567890123456789");
        BigInt num14("-1234567890123456789");
        BigInt num15=num13+num14;
        cout<<setw(21)<<"num13 = "<<num13<<endl;
        cout<<setw(21)<<"num14 = "<<num14<<endl;
        cout<<setw(29)<<"num13 + num14 = "<<num15<<endl<<endl;


        cout<<"test case # 6: now you test "<<endl;
        cout<<"enter the two numbers :"<<endl;
        cout<<"Number 1 : ";
        cin>>n1;
        cout<<"Number 2 : ";
        cin>>n2;
        BigInt num16(n1);
        BigInt num17(n2);
        BigInt num18=num16+num17;
        cout<<setw(21)<<"Number 1 = "<<num16<<endl;
        cout<<setw(21)<<"Number 2 = "<<num17<<endl;
        cout<<setw(32)<<"Number 1 + Number 2 = "<<num18<<endl<<endl;
        cout<<"size of Number 1 :"<<num16.getRealsize()<<endl;
        cout<<"size of Number 2 : "<<num17.getRealsize()<<endl;
        cout<<"size of sum : "<<num18.getRealsize()<<endl;


    }
    catch(string s){

        cout<<endl<<"Error!!!! : \" "<<s<<" \" is a wrong number"<<endl;

    }
    catch(...)
    {
        cout<<"oops, sorry something wrong go back to the developer"<<endl;
    }









}
