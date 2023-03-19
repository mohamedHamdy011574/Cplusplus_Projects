#include "BigInt.h"
#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

// default constructor , initialize the string myNumber and the size and the sign variable
BigInt::BigInt()
{
   myNumber="";
   sign='+';
   numSize=0;
}

// parametrized constructor , that take a string as a parameter and give it to my string
BigInt::BigInt( string myNumber)
{
    if(!checkNumber(myNumber))      // check the validation of the number and if it not valid throw exception
        throw (myNumber);

    if(myNumber[0]=='-'){          // if number is negative store the '-' sign in variable called sign
        sign='-';
        myNumber.erase(0,1);      // erase the sign to make adding simple and in the end i put it back again in the number
    }
    else if (myNumber[0]=='+'){  // handle the '+' sign  by the same way we handle the '-'  sign
        sign='+';
        myNumber.erase(0,1);
    }
    else{                  // if the number enter without sign like ( 1 , 11 ,120 ,etc) we consider the sign as it is + include 0
        sign='+';
    }
    if(myNumber != "0"){       // if the first index is zero we must check if there is zeros we don't need and delete them
        handleZeors(myNumber);
    }
    numSize=myNumber.size();    // put the size of the string in variable called numSize after erasing the zeros we don't need and check validation
    this->myNumber=myNumber;    // put my string from the parameter my number into the variable my number in the class


}

// parametrized constructor that take number with data type long long  as a parameter
BigInt::BigInt(long long Number)
{
   if(Number >= 0)             // if number is >= 0 the sign will be '+'
        sign='+';
   else{
        sign='-';                  // if number < 0 the sign will be '-'
        Number = Number * -1;     //  multiply the number by -1 to make addition easy and we will display the number by its sign in the end
    }

   myNumber=to_string(Number);    // casting by convert long long to string to perform the addition in the next step t
   handleZeors(myNumber);        // handle the zeros we don't need
   numSize=myNumber.size();

}

//copy constructor
BigInt::BigInt(const BigInt& otherObj)
{

        // copy the data of the first object to my object
        numSize=otherObj.numSize;
        myNumber=otherObj.myNumber;
        handleZeors(myNumber);
        sign=otherObj.sign;


}

// getter that return the size of my string (the number of digits on my string)
long long BigInt::getRealsize()const
{
    return numSize;
}

//operator overloading to '==' operator
bool BigInt::operator ==( BigInt& rightObj)
{
    if(sign==rightObj.sign)                       // if the 2 number has the same size   ex: check if 12 == 10
        return myNumber==rightObj.myNumber;      //  return the result of comparing the 2 strings
    else
        return false;                           // ex: -12 == 12 or 122 == -120 , the two number has different sign so we return false direct
}

//operator overloading to '=' assignment operator
BigInt BigInt::operator=(const BigInt& otherObj)
{
    if(&otherObj != this)                  // if the parameter is not the same obj like s = s , so we copy the information
    {                                     // of the  parameter object into my object
        numSize=otherObj.numSize;
        myNumber=otherObj.myNumber;
        sign=otherObj.sign;
    }

    return *this;                         // else if s = s return *this direct
}

// operator overloading of '+' to perform my addition
BigInt BigInt::operator+( BigInt& rightObj)
{
    // handle if the two numbers not equal each other i make them has the same size to perform addition easily
    while(myNumber.size()>rightObj.myNumber.size())
    {
        rightObj.myNumber.insert(0,"0");     // ex: 12 + 1 i make it 12 + 01 until i finish my addition and i will delete zeros again
    }
    while(myNumber.size()<rightObj.myNumber.size())
    {
        myNumber.insert(0,"0");            // ex: 12 + 122 i make it 012 + 122
    }

    // string to store my result
    BigInt strSum;

    if((sign=='-' && rightObj.sign=='-' )||(sign=='+' && rightObj.sign=='+'))      // case 1,2 : if two numbers has the same sign
    {
        //reverse the strings to perform addition normally ex:122 +125 i add the numbers form left to right
       //so i reverse the string to perform addition and i will reverse back in the end
        reverse(myNumber.begin(), myNumber.end());
        reverse(rightObj.myNumber.begin(), rightObj.myNumber.end());

        //                                                                                                         1
        // carry to store the carry that come from add two numbers >=5                                             15 + 15
        // we add 5 + 5 first and result = 10 so i put zero in result and carry will be 1 , then carry+1+1=3         30
        int carry = 0;

        for (int i=0; i<myNumber.size(); i++)
        {

            // current digits and carry
            int sum = ((myNumber[i]-48)+(rightObj.myNumber[i]-'0')+carry);
            strSum.myNumber.push_back(sum%10 + 48);

            // Calculate carry for next step
            carry = sum/10;
        }                                                //                                                            1
        if (carry==1)                                   // to handle the carry after adding all all digits              52 +52
            strSum.myNumber.push_back(carry+48);       //  2+2= 4 and when we make 5+5=10 we have 1 as carry             104

        //reverse back all the strings to get the number from right to left to display it correctly
        reverse(strSum.myNumber.begin(), strSum.myNumber.end());
        reverse(myNumber.begin(), myNumber.end());
        reverse(rightObj.myNumber.begin(), rightObj.myNumber.end());

        // handling the zeros i don't need either in the 2 numbers that be added or the result
        handleZeors(myNumber);
        handleZeors(rightObj.myNumber);
        handleZeors(strSum.myNumber);

        //keep track the size of my strings without any extra zeros bec i handle it before
        numSize=myNumber.size();
        rightObj.numSize=rightObj.myNumber.size();
        strSum.numSize=strSum.myNumber.size();

        // give each number its sign and the sign of result also to show it correctly in the screen
        if(sign=='-')
        {
            if(strSum.myNumber!="0" && strSum.myNumber!="")
            strSum.myNumber.insert(0,"-");

            if(myNumber!="0" && myNumber!="")
            myNumber.insert(0,"-");

            if(rightObj.myNumber!="0" && myNumber!="")
            rightObj.myNumber.insert(0,"-");
        }

    }

    else if(sign=='-' && rightObj.sign=='+' || sign=='+' && rightObj.sign=='-')  // case 3,4: if the two numbers has different signs
    {
        if(myNumber>=rightObj.myNumber)          // ex: -10 + 9   or  10 + (-9)  we handle it by same way
        {
            strSum = *this - rightObj;         // return 10 - 9  and handle '-' in the next step

            handleZeors(strSum.myNumber);
            strSum.numSize=strSum.myNumber.size();

            // sign of result will follow the sign of the largest number
            if(this->sign=='-' && strSum.myNumber != "0"){     // if -10 + 9 so make 10 - 9 = 1 and add '-' to result to became -1
                strSum.myNumber.insert(0,"-");                //  if 10 + (-9) so make 10 - 9 = 1 and we don't add any sign

            }
        }
        else if(myNumber<rightObj.myNumber)    // ex: -9 + 10 or 9 + -(10) we handle it by same way
        {
            strSum = rightObj - *this;        // return 10 - 9  and we handle '-' in the next step

            handleZeors(strSum.myNumber);
            strSum.numSize=strSum.myNumber.size();

            // sign of result will follow the sign of the largest number
            if(rightObj.sign=='-' && strSum.myNumber != "0"){    // if -9 + 10 so make 10 - 9 = 1 and don't add any sign
                strSum.myNumber.insert(0,"-");                  // if 9 + (-10) so make 10 - 9 = 1 and add '-' to result to became -1
            }
        }

        // handle the extra zeros that i added if the size of 2 numbers are not equal to display them correctly
        handleZeors(myNumber);
        handleZeors(rightObj.myNumber);

        numSize=myNumber.size();
        rightObj.numSize=rightObj.myNumber.size();

        // handle the sign of the 2 number
        if(this->sign=='-' && this->myNumber != "0")
            myNumber.insert(0,"-");
        if(rightObj.sign=='-' && rightObj.myNumber != "0")
            rightObj.myNumber.insert(0,"-");

    }


    // return the result string from addition
    return strSum;


}

// operator overloading for '-' operator to perform subtraction easily , i use it only to handle -ve numbers on addition only
// so i did not handle other cases like 10 - (-10) or -10 - 10 or -10 - (-10) bec my problem want me to add only and handle -ve number
// not more
BigInt BigInt::operator-( BigInt& rightObj)
{
    while(numSize>rightObj.numSize)
    {
        rightObj.myNumber.insert(0,"0");
        rightObj.numSize=rightObj.myNumber.size();
    }
    while(numSize<rightObj.numSize)
    {
        myNumber.insert(0,"0");
        numSize=myNumber.size();
    }

    BigInt strSubtract;


        reverse(myNumber.begin(), myNumber.end());
        reverse(rightObj.myNumber.begin(), rightObj.myNumber.end());

        int carry = 0;
        for (int i=0; i<myNumber.size(); i++)
        {
            // current digits and carry
            int subtract = ((myNumber[i]-48)-(rightObj.myNumber[i]-'0')-carry);


        if (subtract<0){
            subtract+=10;
            carry=1;
            }
        else
            carry=0;

        strSubtract.myNumber.push_back(subtract+48);

        }
            reverse(strSubtract.myNumber.begin(), strSubtract.myNumber.end());
            reverse(myNumber.begin(), myNumber.end());
            reverse(rightObj.myNumber.begin(), rightObj.myNumber.end());

            return strSubtract;

}

// operator overloading to '<<' operator to print my numbers easily
ostream& operator<<(ostream& output,const BigInt& myObj)
{
    output<<myObj.myNumber;
    return output;
}
