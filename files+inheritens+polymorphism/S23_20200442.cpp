#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

int positiveIgnored=0,NegativeIgnored=0;       // a counter to count the numbers which i will be ignored int positive/negative array

class FloatArray
{
    protected:
                                // 2 protected member variables 1- dynamic array carry only float numbers , 2- the size of the array
        float *floatArr;       // why protected ?.. -> to allow the 2 variables to be inherited to another classes
        int sizeOfArr;

    public:

        FloatArray(int s)           // a parametrized constructor which take one parameter : the size of array
        {
            sizeOfArr=s;
            floatArr=new float[sizeOfArr];       //dynamic allocation to the dynamic array

            for(int i=0;i<sizeOfArr;i++)        // for loop to give all the index an starting number that can not be entered by user
                floatArr[i]=-999999;           // if number = -999999 we assume that the index is empty
        }

       virtual void addNewNumber(float num)      // add method which take number and add it to the array and it is virtual because we will use polymorphism
        {
            for(int i=0;i<sizeOfArr;i++)
            {

                if(floatArr[i]==-999999){         // add the number at the end in the array (arr[0],arr[1],arr[2],etc..)
                    floatArr[i]=num;
                    break;
                }
            }

        }
         friend ofstream& operator<<(ofstream&,FloatArray&);           // overloading to << operator to print the arrays into output file
         friend ifstream& operator>>(ifstream&,FloatArray&);          //  overloading to >> operator to read the arrays from input file

       virtual ~FloatArray()            // a destructor to delete the array ( must be virtual when we have at least one virtual in our class)
        {
            delete []floatArr;
        }


};
ofstream& operator<<(ofstream& f2,FloatArray& Right)        // definition of the overloading function
{

    for(int i=0;i<Right.sizeOfArr;i++)              // for loop to print all the array in the output file
    {
        if(Right.floatArr[i]!=-999999)             // if the index have our dummy number -999999 this mean it is empty and do not print this index
            f2<<setw(10)<<left<<Right.floatArr[i];
    }
    return f2;           // return object from type ofstream
}
 ifstream& operator>>(ifstream& f1,FloatArray& Right)
{
    float num;               // a variable from type float to allow us to read numbers of arrays one by one from the input file
    for(int i=0;i<Right.sizeOfArr;i++)
    {
        f1>>num;                        // read the number
        Right.addNewNumber(num);       // calling the add function (according to in which class we are)
    }
    return f1;         // return object from type ifstream
};

class SortedArray:public FloatArray            // class SortedArray which inherits from class FloatArray
{
    public:

        SortedArray(int s):FloatArray(s){}     // a parametrized constructor that do nothing but take the size and passing it the base constructor only

        virtual void addNewNumber(float num)  // add method to class SortedArray
        {
            if(floatArr[0]==-999999)        // if we stand on the first index put the number directly in index 0
                floatArr[0]=num;

            else{                          // else we add the number in his right place (we don't add the number then sorted its not allowed)

                int flag=0,x=0;       // a flag that show me if i have a number < numberWeAdd or not , and an variable x to save the index of the number < addedNumber (if there is one)

                for(int i=sizeOfArr-1;i>=0;i--)       // for loop work from the end of the array to the starting point of the array
                {
                    if(floatArr[i]<num && floatArr[i]!=-999999)          // if the is number < numberWeAdd  and not = -999999
                    {
                        flag=1;                              // flag become true ( = 1)
                        x=i;                                // 'x' will save the index of this number to add the new number after it directly
                        break;                             // break the loop to reduce the time
                    }
                }
                if(flag==1 && floatArr[sizeOfArr-1]==-999999)  // if we have the number < numberWeAdd and we still have space in our array (last index == -999999)
                {
                    for(int i=sizeOfArr-2;i>=0;i--)      // for loop to shift all the numbers (after the 'number < numberWeAdd' ) to the right until the end of the array
                    {
                        if(i!=x)                            // keep shifting until i reach that number if i reach to the 'number < numberWeAdd'
                            floatArr[i+1]=floatArr[i];

                        else if(i==x){                        //if i reach to the 'number < numberWeAdd'
                            floatArr[x+1]=num;               // add the 'numberWeAdd' after this number directly the break
                            break;
                            }
                    }
                }
                else if (flag==0 && floatArr[sizeOfArr-1]==-999999)     // else if we have not a number which is < numberWeAdd , so the numberWeAdd < all the numbers in the array
                {
                    for(int i=sizeOfArr-2;i>=0;i--)
                    {
                        if(i!=x)                         // shift all the numbers to lift until we reach the first index
                            floatArr[i+1]=floatArr[i];

                        else if(i==0){                   // if we reach the first index  of the array complete the last step of shifting then  put the numberWeAdd to this index
                            floatArr[1]=floatArr[0];         // last step of shifting to the right
                            floatArr[0]=num;                // adding the numberWeAdd then break
                            break;
                        }
                    }

                }
            }

        }






};
class FrontArray:public FloatArray         // class FrontArray which inherits from class FloatArray
{
    public:

        FrontArray(int s):FloatArray(s){}

        void addNewNumber(float num)           // add method to add the numberWeAdd in the front of the array
        {

            for(int i=sizeOfArr-1;i>=0;i--)
            {
                if(floatArr[i]==-999999){
                    floatArr[i]=num;
                    break;
                }
            }
        }
};
class PositiveArray:public SortedArray        //class positiveArray which inherits from class SorrtedArray
{
    public:

        PositiveArray(int s):SortedArray(s){}

        void addNewNumber(float num)           // add method to add the numberWeAdd to the array if it is positive only
        {
            if(num >0)
                SortedArray::addNewNumber(num);          // then use the add method of SorrtedArray
            else
                NegativeIgnored++;       // if the numberWeAdd is not positive increase my Negative counter  by 1
        }
};

class NegativeArray:public SortedArray        //class NegativeArray which inherits from class SorrtedArray
{
    public:

        NegativeArray(int s):SortedArray(s){}

        void addNewNumber(float num)                 // add method to add the numberWeAdd to the array if it is negative only
        {
            if(num<0)
                SortedArray::addNewNumber(num);        // then use the add method of SorrtedArray
            else
                positiveIgnored++;          // if the numberWeAdd is not negative increase my positive counter  by 1
        }
};





int main()
{
    ifstream f1;
    ofstream f2;

    string filename_1,filename_2,ArrName;
    int sizee=0;

    cout<<"Enter the name of the input file: \n";
    getline(cin,filename_1);
    cout<<"Enter the name of the output file: \n";
    getline(cin,filename_2);

    cout<<endl;

    f1.open(filename_1.c_str());
    f2.open(filename_2.c_str());

    FloatArray* myArray;

if(f1)                      // if the input file is successfully opened
{
    for(int x=0;x<10;x++)
    {
        f1>>ArrName>>sizee;             // read the name of the array and its size

        if(ArrName[0]>=48 && ArrName[0]<=57)      // if the name of the array is not a string of alphaphet
        {
            cout<<"there is an error ,please check for each array that ' number of numbers = size ' "<<endl;
            break;
        }

            if(ArrName=="Array" || ArrName=="array")
                myArray=new FloatArray(sizee);
            else if (ArrName=="Sorted"|| ArrName=="sorted")
                myArray=new SortedArray(sizee);
            else if(ArrName=="Front" || ArrName=="front")
                myArray=new FrontArray(sizee);
            else if(ArrName=="Positive" || ArrName=="positive")
                myArray=new PositiveArray(sizee);
            else if(ArrName=="Negative" || ArrName=="negative")
                myArray=new NegativeArray(sizee);
            else
            {
                cout<<"we have an array names not included in our list please check your input"<<endl;
                break;
            }

        f1>>*myArray;

        if(ArrName=="Positive" || ArrName=="positive")        //if condition to change the output size of array
        {
            sizee-=NegativeIgnored;
        }

        if(ArrName=="Negative" || ArrName=="negative")       //if condition to change the output size of array
        {
            sizee-=positiveIgnored;
        }
        f2<<sizee;
        f2<<"|    ";
        f2<<*myArray<<endl;

        delete myArray;            // deallocate objects

    }
}

else         // if the input file is not open
{
    cout<<"there is an error, file ' "<<filename_1<<" ' not open"<<endl;
}



    f1.close();
    f2.close();




}
