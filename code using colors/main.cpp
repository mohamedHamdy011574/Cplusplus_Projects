#include <iostream>


using namespace std;

#ifndef SETCOLORFUN_H_INCLUDED
#define SETCOLORFUN_H_INCLUDED
#include <windows.h>
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

/*
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/


#endif // SETCOLORFUN_H_INCLUDED
class ColoredBox
{
private:
    char**theBox;
    char boxCharacter;
    int boxLen,boxWid,boxColor,boxArea;
    static int maxArea;
public:
    ColoredBox(int,int,int,char); // the constructor which construct the block of the box

    void setLength(int L);       // 1- setter to length
    void setWidth(int W);        // 2- setter to width
    void setColor(int Col);      // 3- setter to color

    int getLength()const;       // 4- return the length
    int getWidth()const;        // 5- return the width
    int getArea()const;         // 6- return the area
    int getColor()const;        // 7- return the color's number

    static int getMaxArea() // 8- return the largest area
    {
        return maxArea;
    }
    void display()const;             // 9- print the original box without any edit
    void displayWider()const;        // 10- print the box with spaces between each character
    void displayTransposed();        // 11- print the transposed of the box
    void displayChess(int)const;     // 12- display the box with 2 colors

    ~ColoredBox();

};int ColoredBox::maxArea=-1;

    ColoredBox::ColoredBox(int L,int W,int Col=15,char Char='#')  // definition for the constructor
    {
        if(L>0 && W>0)
        {
            boxLen=L;
            boxWid=W;
        }
        else
        {
            cout<<"please rerun the code again, because an invalid length or width /n";
        }
        boxColor=Col;
        boxCharacter=Char;
        boxArea=boxLen*boxWid;

        if(boxArea>maxArea)
        {
            maxArea=boxArea;
        }

        theBox=new char*[boxLen];
        for(int i=0;i<boxLen;i++)
            theBox[i]=new char[boxWid];

        for(int a=0;a<boxLen;a++)
            for(int b=0;b<boxWid;b++)
                theBox[a][b]=boxCharacter;

    }

   /* all setters and getters definitions except static member function*/

    void ColoredBox::setLength(int Len)
    {
        boxLen=Len;
    }
    void ColoredBox::setWidth(int wid)
    {
        boxWid=wid;
    }
    void ColoredBox::setColor(int color)
    {
        boxColor=color;
    }
    int ColoredBox::getLength()const
    {
        return boxLen;
    }
    int ColoredBox::getWidth()const
    {
        return boxWid;
    }
    int ColoredBox::getColor()const
    {
        return boxColor;
    }
    int ColoredBox::getArea()const
    {
        return boxArea;
    }

    /* all definitions of all types of display functions */

    void ColoredBox::display()const
    {
        SetColor(boxColor);
        for(int l=0;l<boxLen;l++){
            for(int w=0;w<boxWid;w++)           // print the original box with the color that the user want
                cout<<theBox[l][w];
            cout<<endl;
        }
        SetColor(15);

    }

    void ColoredBox::displayTransposed()
      {
          SetColor(boxColor);
        for(int w=0;w<boxWid;w++){             // transpose the box by change the outer loop with the inner loop
            for(int l=0;l<boxLen;l++)          // length transpose to be the width and vice versa and print the box
                cout<<theBox[l][w];
            cout<<endl;
        }
        SetColor(15);

    }

    void ColoredBox::displayWider()const
    {
        SetColor(boxColor);

        for(int l=0;l<boxLen;l++){
            for(int w=0;w<boxWid;w++)
                cout<<theBox[l][w]<<" ";         // display the box by a spaces between each character
            cout<<endl;
        }

        SetColor(15);

    }
    void ColoredBox::displayChess(int col2)const
    {
        int x=1;    // let the x is the value in which the color change to col 2

        for(int l=0;l<boxLen;l++){
            for(int w=0;w<boxWid;w++){
                if(w==x){
                    SetColor(col2);        // check if the index of the column is equal to x to change the color
                    x+=2;
                }
                else{
                    SetColor(boxColor);     // if not remain the same color used before
                }
                cout<<theBox[l][w];
            }
            cout<<endl;
            if(l%2==0)        // an idea  that i used to check if the number of row is even or odd to change the correct index
                x=0;         // so if i stand on first row(l=0 -> even)  change col with index(1,3,5,...etc -> odd) but if i stand on
            else             // the second row(l=1 -> odd) change col(0,2,4,...etc  -> even) I hope it;s cleared .
                x=1;
        }

        SetColor(15);

    }


    ColoredBox::~ColoredBox()
    {

        for(int l=0;l<boxLen;l++)
            delete []theBox[l];         // the destructor that delete the dynamic allocation of the 2d array "the box"
        delete []theBox;
    }
int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea()<<endl;
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}
