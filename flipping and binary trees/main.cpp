#include <iostream>

using namespace std;

struct Tree_Node
{
    int data;
    Tree_Node* right;
    Tree_Node* left;
    Tree_Node(int dt){ data=dt ;right=0; left=0;}
};
Tree_Node* root=0;


void inOrder(const Tree_Node* r = root){
     if(r != 0)
        { inOrder(r->left);
          cout<<r->data<<" ";
           inOrder(r->right);
        }
}


void flip(Tree_Node*& r = root)
{
    if(r == 0)
        return;

    else
    {
        Tree_Node* tempLeft=r->left;
        r->left = r->right;
        r->right = tempLeft;
        flip(r->left);
        flip(r->right);
    }
}
int main()
{
    cout<<"Test case 1 :"<<endl;
    root=new Tree_Node(1);
    root->left=new Tree_Node(2);
    root->left->left=new Tree_Node(4);
    root->left->right=new Tree_Node(5);
    root->right=new Tree_Node(3);

    inOrder();
    cout<<endl;
    flip();
    inOrder();
    cout<<endl<<endl;
    delete root;

    cout<<"Test case 2 :"<<endl;
    Tree_Node* root2=new Tree_Node(1);
    root2->left=new Tree_Node(2);
    root2->left->left=new Tree_Node(3);
    root2->left->right=new Tree_Node(4);
    root2->right=new Tree_Node(5);
    root2->right->left=new Tree_Node(7);

    inOrder(root2);
    cout<<endl;
    flip(root2);
    inOrder(root2);
    cout<<endl<<endl;
    delete root2;

    cout<<"Test case 3 :"<<endl;
    Tree_Node* root3=new Tree_Node(9);
    root3->left=new Tree_Node(10);
    root3->left->left=new Tree_Node(11);
    root3->right=new Tree_Node(12);
    root3->right->left=new Tree_Node(13);

    inOrder(root3);
    cout<<endl;
    flip(root3);
    inOrder(root3);
    cout<<endl<<endl;
    delete root3;

    cout<<"Test case 4 right sk.:"<<endl;
    Tree_Node* root4=new Tree_Node(1);
    root4->right=new Tree_Node(2);
    root4->right->right=new Tree_Node(3);
    root4->right->right->right=new Tree_Node(4);

    inOrder(root4);
    cout<<endl;
    flip(root4);
    inOrder(root4);
    cout<<endl<<endl;
    delete root4;

    cout<<"Test case 5 :"<<endl;
    Tree_Node* root5=new Tree_Node(1);
    root5->left=new Tree_Node(2);
    root5->left->left=new Tree_Node(3);
    root5->left->right=new Tree_Node(4);
    root5->right=new Tree_Node(5);

    inOrder(root5);
    cout<<endl;
    flip(root5);
    inOrder(root5);
    cout<<endl;
    delete root5;


}
