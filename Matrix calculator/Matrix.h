#ifndef MATRIX_
#define MATRIX_
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<class t>
class Matrix
{
    // private attributes to store the rows and columns of my matrix
    private:
        t **myMatrix;
        int matrixRows;
        int matrixCols;

    public:

        //constructors for the class
        Matrix();
        Matrix(int,int);
        Matrix(const Matrix<t>&);

        //setters and getters for the rows and columns to allow access it if we use default constructor
        void setRows(int r){ matrixRows=r;}
        void setCols(int c){ matrixCols=c;}
        int getCols()const{ return matrixCols;}
        int getRows()const{ return matrixRows;}

        //operator overloading for '<<' to print a matrix from a specific object
        friend ostream& operator<<(ostream& output,const Matrix<t>& rightObj)
         {
            output<<endl<<"The result: "<<endl;
            for(int i=0;i<rightObj.matrixRows;i++)
            {
                for(int j=0;j<rightObj.matrixCols;j++)
                {
                    output<<rightObj.myMatrix[i][j]<<" ";
                }
                output<<endl;
            }
            output<<endl;
            return output;
         }

         //operator overloading for '>>' to take a matrix for a specific object as an input from user
          friend istream& operator>>(istream& input,Matrix<t>& rightObj)
        {
                for(int i=0;i<rightObj.matrixRows;i++)
                {
                    for(int j=0;j<rightObj.matrixCols;j++)
                    {
                        input>>rightObj.myMatrix[i][j];
                    }
                }
                return input;
        }



        //operator overloading for some operators like ( = , + , - , * ) to make some operations on 2 matrixies
        Matrix<t>& operator=(const Matrix<t>&);
        Matrix<t> operator+(const Matrix<t>&);
        Matrix<t> operator-(const Matrix<t>&);
        Matrix<t> operator*(const Matrix<t>&);

        // function that transpose my matrix
        void transpose();

        // destructor to free the dynamic memory allocations
        ~Matrix();

};

// default constructor that allocate my 2D matrix in memory with row and columns =1 and data=0  matrix=[0]
template<class t>
Matrix<t>::Matrix()
{
    matrixRows=1;
    matrixCols=1;
    myMatrix = new t*[matrixRows];

    for(int i=0;i<matrixRows;i++)
    {
        myMatrix[i]=new t[matrixCols];
    }
    for(int i=0;i<matrixRows;i++)
        {
            for(int j=0;j<matrixCols;j++)
            {
                myMatrix[i][j]=0;
            }
        }
}

// a parametrized constructor that take a row and columns of my 2D matrix as an arguments and allocate a 2D matrix in memory
// with rows=r and cols=c  and all data inside this matrix = 0
template<class t>
Matrix<t>::Matrix(int r,int c)
{
    matrixRows=r;
    matrixCols=c;

    myMatrix = new t*[matrixRows];
    for(int i=0;i<matrixRows;i++)
    {
        myMatrix[i]=new t[matrixCols];
    }
    for(int i=0;i<matrixRows;i++)
    {
        for(int j=0;j<matrixCols;j++)
        {
            myMatrix[i][j]=0;
        }
    }

}// a copy constructor that take an object as a parameter and copy all its information in my object
template<class t>
Matrix<t>::Matrix(const Matrix& otherObj)
{

    // make a 2D matrix with same dimensions as the object i take as a parameter

    matrixRows=otherObj.matrixRows;
    matrixCols=otherObj.matrixCols;

    myMatrix = new t*[matrixRows];
    for(int i=0;i<matrixRows;i++)
    {
        myMatrix[i]=new t[matrixCols];
    }

    for(int i=0;i<matrixRows;i++)
    {
        for(int j=0;j<matrixCols;j++)
        {
            myMatrix[i][j]=otherObj.myMatrix[i][j];
        }
    }

}

// operator overloading for '=' operator to allow use  m1 = m2 , note : not work as same as copy constractor behavior
template<class t>
Matrix<t>& Matrix<t>::operator =(const Matrix& otherObj)
{

    if(&otherObj != this){           // if the object i take from parameters is not the same object i stand on it like m1 = m1

        for(int i=0;i<matrixRows;i++)       // ex: m1 =m2 ,so i free my memory in m1 and copy all information from m2 to m1 (deep copy)
        {
            delete[]myMatrix[i];
        }
        delete[]myMatrix;


        //allocate a new matrix by same information of the matrix from the object from the parameter
        matrixRows=otherObj.matrixRows;
        matrixCols=otherObj.matrixCols;

        myMatrix = new t*[matrixRows];
        for(int i=0;i<matrixRows;i++)
        {
            myMatrix[i]=new t[matrixCols];
        }

        for(int i=0;i<matrixRows;i++)
        {
            for(int j=0;j<matrixCols;j++)
            {
                myMatrix[i][j]=0;
            }
        }

        for(int i=0;i<matrixRows;i++)
        {
            for(int j=0;j<matrixCols;j++)
            {
                myMatrix[i][j]=otherObj.myMatrix[i][j];
            }
        }
    }
    return *this;

}

// operator overloading of '+' operator to add 2 matrixies  ( m1 + m2 )
template<class t>
Matrix<t> Matrix<t>::operator+(const Matrix<t>& rightObj)
{
    // make a new object of matrix and it will contain the result of addition
    Matrix<t> mySum(matrixRows,matrixCols);

    // add the 2 matrixies 1 by 1 and put the result in my new matrix inside object 'mySum'
    for(int i=0;i<mySum.matrixRows;i++)
    {
        for(int j=0;j<mySum.matrixCols;j++)
        {
            mySum.myMatrix[i][j]=myMatrix[i][j]+rightObj.myMatrix[i][j];
        }
    }

    return mySum;
}

// operator overloading for '-' operator to perform subtraction on 2 matrixies ( m1 - m2 )
template<class t>
Matrix<t> Matrix<t>::operator-(const Matrix<t>& rightObj)
{
    //allocate a new matrix that hold the result of subtraction
    Matrix<t> mySubtraction(matrixRows,matrixCols);

    //subtract the elements of m2 from the elements of matrix m1
    for(int i=0;i<mySubtraction.matrixRows;i++)
    {
        for(int j=0;j<mySubtraction.matrixCols;j++)
        {
            mySubtraction.myMatrix[i][j]=myMatrix[i][j]-rightObj.myMatrix[i][j];
        }
    }
    return mySubtraction;

}

//operator overloading for '*' operator to perform multiplication on 2 matrixies ( m1 * m2 )
template<class t>
Matrix<t> Matrix<t>::operator*(const Matrix<t>& rightObj)
{
    //allocate a new matrix to hold the result of the multiplication
    Matrix<t> myMultiplication(matrixRows,rightObj.matrixCols);

    // perform the multiplication process
    for(int i=0;i<myMultiplication.matrixRows;i++)
    {
        for(int j=0;j<myMultiplication.matrixCols;j++)
        {
            //a variable to holds the summation of the m1[i][k]*m2[k][j]
            myMultiplication.myMatrix[i][j]=0;
            for(int k=0;k<matrixCols;k++)
            {
                myMultiplication.myMatrix[i][j]+=myMatrix[i][k]*rightObj.myMatrix[k][j];

            }

        }
    }


    return myMultiplication;

}

// transpose function that transpose my matrix ( cols become rows and rows become cols),for square or non square matrix
template<class t>
void Matrix<t>::transpose()
{
        // a temp Matrix that hold the matrix after transpose it , we use it to copy it again to the original matrix after free the original
        Matrix<t> tempMatrix(matrixCols,matrixRows);

        for(int i=0;i<tempMatrix.getRows();i++)
        {
            for(int j=0;j<tempMatrix.getCols();j++)
            {
                tempMatrix.myMatrix[i][j]=myMatrix[j][i];
            }
        }


        // free the original matrix
        for(int i=0;i<matrixRows;i++)
        {
            delete[]myMatrix[i];
        }
        delete[]myMatrix;

        // assign the new cols and rows for the original matrix
        matrixRows=tempMatrix.getRows();
        matrixCols=tempMatrix.getCols();


        //allocate the original matrix again with the new cols and rows
        myMatrix = new t*[matrixRows];
        for(int i=0;i<matrixRows;i++)
        {
            myMatrix[i]=new t[matrixCols];
        }

        // copy the value of temp matrix to the original matrix and the original matrix transpose completlly
        for(int i=0;i<matrixRows;i++)
        {
            for(int j=0;j<matrixCols;j++)
            {
                myMatrix[i][j]=tempMatrix.myMatrix[i][j];
            }
        }
}

//destructor to free my dynamic memory allocation
template<class t>
Matrix<t>::~Matrix()
{
    for(int i=0;i<matrixRows;i++)
    {
        delete[]myMatrix[i];
    }
    delete[]myMatrix;
}

#endif // MATRIX_
