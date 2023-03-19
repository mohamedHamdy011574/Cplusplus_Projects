#include <iostream>
#include "BST.h"

        bool isSame(BstNode<int>* r1 ,BstNode<int>* r2)
        {
            if(r1==0 && r2==0)
                return true;
            if(r1!=0 && r2!=0 )
                return (r1->data == r2->data && isSame(r1->left,r2->left) && isSame(r1->right,r2->right));

            return false;
        }

         bool isSubTree(BstNode<int>*r1,BstNode<int>*r2)
        {
            if(r2 == 0)
                return true;

            if(r1 == 0)
                return false;

            if(isSame(r1,r2))
                return true;

            if(r2->data < r1->data)
                return isSubTree(r1->left,r2);

            return isSubTree(r1->right,r2);


        }
        bool isSubTree(BstFci<int>* t1,BstFci<int>* t2)
        {
            return isSubTree(t1->getRoot(),t2->getRoot());
        }

using namespace std;

int main()
{

    BstFci<int> myTree(5);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(1);
    myTree.insert(9);
    myTree.insert(10);
    myTree.insert(8);



    myTree.print();
    cout<<"\t";
    if(myTree.isBalance())
        cout<<"balanced tree";
    else
        cout<<"unbalanced tree";
    cout<<endl<<endl;

    BstFci<int> myTree2(5);
    myTree2.insert(3);
    myTree2.insert(7);
    myTree2.insert(2);
    myTree2.insert(4);


    myTree2.print();
    cout<<"\t";
    if(myTree2.isBalance())
        cout<<"balanced tree";
    else
        cout<<"unbalanced tree";
    cout<<endl<<endl;

    BstFci<int> myTree3(5);
    myTree3.insert(3);
    myTree3.insert(7);
    myTree3.insert(2);
    myTree3.insert(4);

    myTree3.print();
    cout<<"\t";
   if(isSame(myTree2.getRoot(),myTree3.getRoot()))
        cout<<" two trees is the same";
    else
        cout<<" two trees isNot the same";
    cout<<endl<<endl;

    BstFci<int> myTree4(9);
    myTree4.insert(10);
    myTree4.insert(8);

    BstFci<int>* t1=&myTree;
    BstFci<int>* t4=&myTree4;

    myTree.print();cout<<"\t";
    myTree4.print();
    if(isSubTree(t1,t4))
        cout<<"\t tree 2 is subtree of 1";
    else
        cout<<"\t tree 2 is not subtree of 1";
    cout<<endl;

    BstFci<int> myTree5(7);
    myTree5.insert(9);
    myTree5.insert(8);
    myTree5.insert(10);

    myTree.print();cout<<"\t";
    myTree5.print();
    if(isSubTree(myTree.getRoot(),myTree5.getRoot()))
        cout<<"\t tree 2 is subtree of 1";
    else
        cout<<"\t tree 2 is not subtree of 1";
    cout<<endl;

    BstFci<int> myTree6(3);
    myTree6.insert(2);
    myTree6.insert(4);

    myTree2.print();cout<<"\t";
    myTree6.print();
    if(isSubTree(myTree2.getRoot(),myTree6.getRoot()))
        cout<<"\t tree 2 is subtree of 1";
    else
        cout<<"\t tree 2 is not subtree of 1";
    cout<<endl;

    BstFci<int> myTree7(3);
    myTree7.insert(2);
    myTree7.insert(1);

    myTree2.print();cout<<"\t";
    myTree7.print();
    if(isSubTree(myTree2.getRoot(),myTree7.getRoot()))
        cout<<"\t tree 2 is subtree of 1";
    else
        cout<<"\t tree 2 is not subtree of 1";
    cout<<endl;

    BstFci<int> myTree8;

    myTree2.print();cout<<"\t";
    myTree8.print();cout<<"NULL TREE";
    if(isSubTree(myTree2.getRoot(),myTree8.getRoot()))
        cout<<"\t tree 2 is subtree of 1";
    else
        cout<<"\t tree 2 is not subtree of 1";
    cout<<endl<<endl;


    myTree.print();
    cout<<endl;
    int maximum=0,minimum=0;
    cout<<"Enter max and min "<<endl;
    cout<<"max: " ;
    cin>>maximum;
    cout<<"min: " ;
    cin>>minimum;
    cout<<"numbers: ";

    myTree.printRange(maximum,minimum);
    cout<<endl<<endl;

    myTree2.print();
    cout<<endl;
    int maximum1=0,minimum1=0;
    cout<<"Enter max and min "<<endl;
    cout<<"max: " ;
    cin>>maximum1;
    cout<<"min: " ;
    cin>>minimum1;
    cout<<"numbers: ";

    myTree2.printRange(maximum1,minimum1);
    cout<<endl<<endl;




}


