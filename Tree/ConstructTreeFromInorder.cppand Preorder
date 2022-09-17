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

void preOrderTraversal(treeNode *root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    chk+=to_string(root->data)+" ";
    preOrderTraversal(root->leftChild,chk);
    preOrderTraversal(root->righChild,chk);

}

void inOrder(treeNode *root, string &chk)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->leftChild,chk);
    chk+= to_string(root->data)+" ";
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


    chk+=to_string(root->data)+" ";
}

int searchInorder(int inOrder[],int current, int start, int end)
{
    for(int i=start; i<=end; i++)
    {
        if(inOrder[i]==current)
        {
            return i;
        }
    }

    return -1;
}

treeNode* buildTreePreIn(int preOrder[],int inOrder[], int start,int end)
{
    static int id  = 0;

    int current = preOrder[id];
    id++;

    treeNode * newNode = new treeNode(current);
    if(start==end)
    {
        return newNode;
    }

    int pos = searchInorder(inOrder,current,start,end);


    newNode->leftChild =  buildTreePreIn(preOrder,inOrder,start,pos-1);
    newNode->righChild =  buildTreePreIn(preOrder,inOrder,pos+1,end);
}

int main()
{
    int n;
    cin>>n;
    int pre[n],in[n];
    for(int i=0; i<n; i++)
    {
        cin>>pre[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>in[i];
    }

    treeNode *root = buildTreePreIn(pre,in,0,n-1);


    string chkPre;

    inOrder(root,chkPre);
    cout<<chkPre<<endl;
    return 0;
}



/*
    sample input

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

*/
