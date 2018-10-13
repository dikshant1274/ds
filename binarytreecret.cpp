#include<iostream>
using namespace std;
struct listnode
{
  char data;
  listnode *next;
};
struct treenode
{
  treenode *left;
  char data;
  treenode *right;
};
void insert(listnode **preptr,char c)
{
  listnode *temp=new listnode;
  temp->data=c;
  if((*preptr)==NULL)
  {
    temp->next=(*preptr);
    (*preptr)=temp;
  }
  else
  {
    listnode *temp1=(*preptr);
    while(temp1->next!=NULL)
    {
      temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
  }
}
treenode* construct(listnode *inptr,listnode *preptr,int num)
{
    treenode *temp;
    listnode *q;
    if(num==0)
    return NULL;
    temp=new treenode;
     temp->data=preptr->data;
     temp->left=NULL;
     temp->right=NULL;
     if(num==1)
     return temp;
      q=inptr;
      int i;
      for(i=0;q->data!=preptr->data;i++)
      {
        q=q->next;
      }
      temp->left=construct(inptr,preptr->next,i);
      for(int j=1;j<=i+1;j++)
      {
        preptr=preptr->next;
      }
      temp->right=construct(q->next,preptr,num-i-1);
        return temp;
}
void preorder(treenode *root)
{
  if(root==NULL)
  return ;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  int n;
  listnode *preptr=NULL;
  listnode *inptr=NULL;
  cin>>n;
  char c;
  for(int i=0;i<n;i++)
  {
    cin>>c;
    insert(&preptr,c);
  }
  for(int i=0;i<n;i++)
  {
    cin>>c;
    insert(&inptr,c);
  }
  treenode *root=construct(inptr,preptr,n);
  preorder(root);
  return 0;
}
