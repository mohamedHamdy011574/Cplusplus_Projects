#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<iostream>
#include<bits/stdc++.h>
#include"Matrix.h"

using namespace std;

class Menu
{
    private:
        int rows;
        int cols;
        int rows2;
        int cols2;

        void performMatrixAddition()
        {
            cout<<endl<<"First Matrix details: "<<endl;
            cout<<"Enter Number Of Rows: "; cin>>rows;
            cout<<"Enter Number Of Columns: "; cin>>cols;
            cout<<endl<<"Second Matrix details: "<<endl;
            cout<<"Enter Number Of Rows: "; cin>>rows2;
            cout<<"Enter Number Of Columns: "; cin>>cols2;

            if(rows==rows2 && cols==cols2){
                Matrix<int> M1(rows,cols);
                cout<<endl<<"Enter Matrix 1"<<endl;
                cin>>M1;
                Matrix<int> M2(rows2,cols2);
                cout<<endl<<"Enter Matrix 2"<<endl;
                cin>>M2;
                cout<<M1+M2;
            }
            else{
                cout<<endl<<"sorry, can not Add 2 matrix with different rows and columns"<<endl;
            }




        }
        void performMatrixSubtraction()
        {
            cout<<endl<<"First Matrix details: "<<endl;
            cout<<"Enter Number Of Rows: "; cin>>rows;
            cout<<"Enter Number Of Columns: "; cin>>cols;
            cout<<endl<<"Second Matrix details: "<<endl;
            cout<<"Enter Number Of Rows: "; cin>>rows2;
            cout<<"Enter Number Of Columns: "; cin>>cols2;

            if(rows==rows2 && cols==cols2){
                Matrix<int> M1(rows,cols);
                cout<<endl<<"Enter Matrix 1"<<endl;
                cin>>M1;
                Matrix<int> M2(rows2,cols2);
                cout<<endl<<"Enter Matrix 2"<<endl;
                cin>>M2;
                cout<<M1-M2;
            }
            else{
                cout<<endl<<"sorry, can not Subtract 2 matrix with different rows and columns"<<endl;
            }
        }
        void performMatrixMultiplication()
        {
            cout<<endl<<"First Matrix details: "<<endl;
            cout<<"Enter Number Of Rows: "; cin>>rows;
            cout<<"Enter Number Of Columns: "; cin>>cols;
            cout<<endl<<"Second Matrix details: "<<endl;
            cout<<"Enter Number Of Rows: "; cin>>rows2;
            cout<<"Enter Number Of Columns: "; cin>>cols2;

            if(rows2==cols){
                Matrix<int> M1(rows,cols);
                cout<<endl<<"Enter Matrix 1"<<endl;
                cin>>M1;
                Matrix<int> M2(rows2,cols2);
                cout<<endl<<"Enter Matrix 2"<<endl;
                cin>>M2;
                cout<<M1*M2;
            }
            else{
                cout<<endl<<"sorry, The Columns of First Matrix must be equal to the Rows of the Second Matrix "<<endl;
            }
        }
        void MatrixTranspose()
        {
            cout<<endl<<"Enter Number Of Rows: "; cin>>rows;
            cout<<"Enter Number Of Columns: "; cin>>cols;
            Matrix<int> M(rows,cols);
            cout<<endl<<"Enter the Matrix "<<endl;
            cin>>M;
            M.transpose();
            cout<<M;
        }

    public:
        void myMenu()
        {
            cout<<setw(200)<<"Welcome \" Mohamed Hamdy \" matrix calculator "<<endl;
            bool stay=true;
            while(stay)
            {
                int select=-1;
                bool flag=true;

                cout<<"1- Perform Matrix Addition"<<endl;
                cout<<"2- Perform Matrix Subtraction"<<endl;
                cout<<"3- Perform Matrix Multiplication"<<endl;
                cout<<"4- Matrix Transpose"<<endl;
                cout<<"Enter 0 if you want to exit"<<endl<<endl;
                while(flag)
                {
                    cout<<"Chose the performance you want: "<<endl;
                    cin>>select;
                    if(select==0 || select==1 || select==2 || select==3 || select==4)
                        flag=false;
                    else
                        flag=true;
                }
                switch(select)
                {
                    case 0:
                        stay=false;
                        break;
                    case 1:
                        performMatrixAddition();
                        break;
                    case 2:
                        performMatrixSubtraction();
                        break;
                    case 3:
                        performMatrixMultiplication();
                        break;
                    case 4:
                        MatrixTranspose();
                        break;

                }
                cout<<endl;
            }

        }


};
#endif // MENU_H_INCLUDED
