// Name : Mohamed Hamdy Mohamed ..... ID : 20200442

#include <iostream>

using namespace std;

const int row=6;
const int col=7;

char IS_WINNING (char ARR[row][col],char P);    // check for winning
void PRINT_BOARD (char ARR[row][col]);     // print the board every turn
bool INSERT(char ARR[row][col],char ch,int column_num);   // check for the empty place

int main()
{
    char ARR[row][col],CharPlayer,gameover=' ';    // declare an array 2D of char of size [6][7] , char player carry 'x' of 'o'
                                                  // gameover carry the return from IS_WINNING function

    int Num0fColumn,x=1;     //NumOfColumn carry the input number of column the player enter   ,  'x' for change between player

    bool y=false;      // 'y' chary the return from INSERT function
    int restart=1;
while (restart!=0)
{
    for(int i=0;i<6;i++)
        for(int j=0;j<7;j++)               // loop in which all elments is assigned to ' '
            ARR[i][j]=' ';

    PRINT_BOARD(ARR);         //calling PRINT_BOARD function

    while(gameover==' ')
    {
        cout<<"its player "<<x<<" turn ,enter the number of column you want (0-6) : ";

        cin>>Num0fColumn;     // take the number of column from the player

        if(x==1)
            CharPlayer='x';     // player 1 play with char 'x'
        if (x==2)
            {
                CharPlayer='o';       // player 2 play with 'o'
                x=0;
                }

        if(Num0fColumn<0 || Num0fColumn>6)          // if any player enter a unvalid number of column enter this loop
        {
            bool flag=true;   // a flag variable which end the loop
            while(flag)
                {
                cout<<"enter a valid number of column please : ";
                cin>>Num0fColumn;

                if(Num0fColumn>=0 && Num0fColumn<=6)
                     y=INSERT(ARR,CharPlayer,Num0fColumn);    // calling function INSERT to check empty place in column or not
                if(y=1 && Num0fColumn>=0 && Num0fColumn<=6)
                    flag=false;    // if Number of column is valid and there is place in column in board end this loop

            }
        }

    for(int i=5;i>=0;i--){
        if(ARR[i][Num0fColumn]==' '){
            ARR[i][Num0fColumn]=CharPlayer;    // if column is not full by x's and o's add the new character
            x++;                               // and increment the x by 1 to change the players
            PRINT_BOARD(ARR);
            break;
        }
        else if(ARR[0][Num0fColumn] !=' '){
            cout<<"the column is full enter another number "<<endl;   // if column is full print is full
            break;                                                    // and keep the turn not change the player
        }


    }

    gameover=IS_WINNING(ARR,CharPlayer);    // carry the return of IS_WINNING in game over to check the winning

}
    if(gameover=='x')
        cout<<"player 1 is the winner \n";
    if(gameover=='o')
        cout<<"player 2 is the winner \n";

    cout<<"are you want a new game ? if no enter 0 , if yes enter any other number. \n";
    cin>>restart;
    if(restart==0)
        exit(0);
    else
        gameover=' ';
    }
}
void PRINT_BOARD(char ARR[row][col])    // print function header and its body
{
    cout<<" 0 1 2 3 4 5 6 "<<endl;
    for(int i=0;i<6;i++){

            cout<<"|";
        for(int j=0;j<7;j++)
            cout<<ARR[i][j]<<",";
        cout<<"|"<<endl<<"|..............|"<<endl;
    }
}
char IS_WINNING(char ARR[row][col], char p)  // function for check the winning (its header and body)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (ARR[i][j] == p && ARR[i+1][j + 1] == p && ARR[i+2][j + 2] == p && ARR[i+3][j + 3] == p) { //Diagonal Right Down Check
                return p;
            }
            if (ARR[i][j] == p && ARR[i][j + 1] == p && ARR[i][j + 2] == p && ARR[i][j + 3] == p) { //Horizontal Check
                return p;
            }
            if (ARR[i][j] == p && ARR[i-1][j + 1] == p && ARR[i-2][j + 2] == p && ARR[i-3][j + 3] == p) { //Diagonal Right Up Check
                return p;
             }
            if (ARR[i][j] == p && ARR[i - 1][j] == p && ARR[i - 2][j] == p && ARR[i - 3][j] == p) { //Vertical Check
                return p;
            }
        }
    }
}
bool INSERT(char ARR[row][col],char ch,int column_num)   // insert function and its body
{
    for(int i=0;i<6;i++)
        if(ARR[i][column_num]==' '){
            return true;
            break;
        }
        else if(i=5)
        {
            if(ARR[i][column_num]!=' '){
                return false;
                break;
            }
        }
}
