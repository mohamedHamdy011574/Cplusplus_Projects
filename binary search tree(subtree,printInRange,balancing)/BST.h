#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<iostream>

using namespace std;

template<class t>
class BstNode
{
    public:
        t data;
        BstNode<t>* left;
        BstNode<t>* right;
        BstNode(){left=0; right=0;}
        BstNode(t dt){data=dt; left=0; right=0;}
};


template<class t>
class BstFci
{
    private:
        BstNode<t>* root;
        int numberOfNodes;

    public:
        BstFci(){root=0; numberOfNodes=0;}
        BstFci(t dt){root=0; numberOfNodes=0;  insert(dt);}

        bool isBalance();
        void printRange(const t& maximum,const t& minimum);

        bool isEmpty(){return root==0;}
        int getSize()const{return numberOfNodes;}
        BstNode<t>* getRoot()const{return root;}
        void insert(t dt){root=insert(root,dt); numberOfNodes++;}
        void print(){inOrder(root);}

        ~BstFci(){treeDelete(root);}
    private:

        BstNode<t>* insert( BstNode<t>* r,const t& dt)
        {
            BstNode<t>* newNode = new BstNode<t>(dt);

            if(r==0)
            {
                r=newNode;
            }
            else if(dt > r->data)
            {
                r->right=insert(r->right,dt);
            }
            else if(dt < r->data)
            {
                r->left=insert(r->left,dt);
            }
            return r;
        }
        void treeDelete(BstNode<t>*& r)
        {
            if(r!=0)
            {
                treeDelete(r->left);
                treeDelete(r->right);
                delete r;
                r=0;
            }
        }
        void inOrder(const BstNode<t>* r)
        {
            if(r!=0)
            {
                inOrder(r->left);
                cout<<r->data<<" ";
                inOrder(r->right);
            }
        }

        int treeHeight (BstNode<t>* r)
        {
            if (r==0)
                return 0;
            else{
                int height=max(treeHeight(r->left),treeHeight(r->right));
                return 1+height;
            }
        }
        bool Balance(BstNode<t>* r)
        {
            if(r==0)
                return true;
            int lSubTreeHeight=treeHeight(r->left);
            int rSubTreeHeight=treeHeight(r->right);

            if(max(lSubTreeHeight,rSubTreeHeight)- min(lSubTreeHeight,rSubTreeHeight)<= 1  && Balance(r->left) && Balance(r->right))
                return true;

            return false;
        }

        void printInRange(BstNode<t>* r,int m1,int m2)
        {
                if(r==0)
                    return;

                if(r->left != 0 && r->data > m1)
                    printInRange(r->left,m1,m2);

                if(r->data>=m1 && r->data <= m2)
                    cout<<r->data<<" ";

                if(r->right !=0 && r->data < m2)
                    printInRange(r->right,m1,m2);

/*
            if (r==0)
                return;

            else
            {
                if(m1 <= r->data)
                    printInRange(r->left,m1,m2);
                if(r->data>=m1 && r->data <= m2)
                    cout<<r->data<<" ";
                if(r->data <= m2)
                    printInRange(r->right,m1,m2);
            }

*/
        }

};
template<class t>
bool BstFci<t>::isBalance()
{
    return Balance(root);
}

template<class t>
void BstFci<t>::printRange(const t& maximum,const t& minimum)
{
    printInRange(root,minimum,maximum);
}

#endif
// BST_H_INCLUDED
