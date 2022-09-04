#include<bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode * leftChild;
    treeNode * righChild;

    treeNode(int val)
    {
        this->data = val;
        leftChild = NULL;
        righChild = NULL;
    }
};

void printSpace(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"   ";
    }
}

void displayTree(treeNode *root, int level)
{
    if(root==NULL)
    {
        return;
    }
    if(root->leftChild == NULL && root->righChild == NULL)
    {
        cout<<root->data<<endl;
    }
    else
    {
        cout<<endl;
        printSpace(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->leftChild!=NULL)
    {
        printSpace(level);
        cout<<"Left: ";
        displayTree(root->leftChild,level+1);

    }

    if(root->righChild!=NULL)
    {
        printSpace(level);
        cout<<"Right: ";
        displayTree(root->righChild,level+1);

    }

}
void preOrder(treeNode *root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    chk+=to_string(root->data);
    preOrder(root->leftChild,chk);
    preOrder(root->righChild,chk);

}

void inOrder(treeNode *root, string &chk)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->leftChild,chk);
    chk+= to_string(root->data);
    inOrder(root->righChild,chk);
}

void postOrder(treeNode *root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->leftChild,chk);
    postOrder(root->righChild,chk);


    chk+=to_string(root->data);
}

int main()
{
    string preorderTraversal;
    string inorderTraversal;
    string postorderTraversal;

    int n;
    cin>>n;
    treeNode* allNode[n];

    for(int i=0; i<n; i++)
    {
        allNode[i] = new treeNode(-1);
    }

    for(int i=0; i<n; i++)
    {
        int value,left,right;

        cin>>value>>left>>right;
        allNode[i]->data = value;

        if(left>n-1 || right>n-1)
        {
            cout<<"Invalid Index"<<endl;
            break;
        }

        if(left!=-1)
        {
            allNode[i]->leftChild = allNode[left];
        }
        if(right!=-1)
        {
            allNode[i]->righChild = allNode[right];
        }
    }

    displayTree(allNode[0],0);

    cout<<"Choice 1: Traverse the Tree Pre-Order"<<endl
        <<"Choice 2: Traverse the Tree In-Order"<<endl
        <<"Choice 3: Traverse the Tree Post-Order"<<endl <<endl;

    int choice;

        cout<<"Choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            preOrder(allNode[0],preorderTraversal);

            cout<<"Preoder Traversal is: "<<preorderTraversal<<endl;
            break;
        case 2:
            inOrder(allNode[0],inorderTraversal);

            cout<<"Inorder traversal is: "<<inorderTraversal<<endl;
            break;
        case 3:
            postOrder(allNode[0],postorderTraversal);

            cout<<"\npostorder traversal is: "<<postorderTraversal<<endl;
            break;
        default:
            break;
        }


    return 0;
}



/*
    sample input

9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

*/
