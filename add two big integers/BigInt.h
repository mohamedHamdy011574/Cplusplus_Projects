#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include<string>

using namespace std;

class BigInt
{
    private:
         int numSize;
         string myNumber;
         char sign;
         // check if the number contain digits only regardless the first index if it '-' or '+'
         bool checkNumber(string s)
         {

            if((s[0]!='-' && s[0]!='+' )&& (s[0]>'9' || s[0]<'0') )    // check the first index if it is not equal '+' or '-'
                return false;                                             // it must be a number and if not then return false

            for( long long i=1;i<s.size();i++)            // check the remaining digits in my string
                    if(s[i]>'9' || s[i]<'0')
                        return false;

            return true;                            // if all characters in my string is digits so return true

            }

        //private function to handling the zeros in the first like 00001 it must be display as 1 or 0012 it display as 12
          void handleZeors(string &myNumber)
          {
                while(myNumber[0] == '0' && myNumber.size()!=1 )   // remove the zeros except the number itself is equal 0
                {
                        myNumber.erase(0,1);
                }

          }

    public:

        // constructors for the class
        BigInt();
        BigInt(string);
        BigInt(long long);
        BigInt(const BigInt&);

        // getter function to get size of the number
        long long getRealsize()const;

        // function overloading to == to check if  two numbers are equal or not
        bool operator ==(BigInt&);

        // overloading for assignment operator
        BigInt operator =(const BigInt&);

        // overloading to + , -  to make operations on the two numbers
        BigInt operator +( BigInt&);
        BigInt operator -( BigInt&);

        // overloading for << operator to print the number
        friend ostream& operator <<(ostream& , const BigInt&);
};

#endif // BIGINT_H
