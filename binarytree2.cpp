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
void insert(listnode **postptr,char c)
{
  listnode *temp=new listnode;
  temp->data=c;
  if((*postptr)==NULL)
  {
    temp->next=(*postptr);
    (*postptr)=temp;
  }
  else
  {
    listnode *temp1=(*postptr);
    while(temp1->next!=NULL)
    {
      temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
  }
}
treenode* construct(listnode *inptr,listnode *postptr,int num)
{
   treenode *temp;
   listnode *ptr,*q;
   if(num==0)
   return NULL;
   ptr=postptr;
   for(int i=1;i<num;i++)
   {
     ptr=ptr->next;
   }
   temp=new treenode;
   temp->data=ptr->data;
   temp->left=NULL;
   temp->right=NULL;
   if(num==1)
   return temp;
   int i;
   q=inptr;
   for(i=0;q->data!=ptr->data;i++)
   q=q->next;
   temp->left=construct(inptr,postptr,i);
   for(int j=1;j<=i;j++)
   {
     postptr=postptr->next;
   }
   temp->right=construct(q->next,postptr,num-i-1);
}
void postorder(treenode *root)
{
  if(root==NULL)
  return ;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

int main()
{
  int n;
  listnode *postptr=NULL;
  listnode *inptr=NULL;
  cin>>n;
  char c;
  for(int i=0;i<n;i++)
  {
    cin>>c;
    insert(&postptr,c);
  }
  for(int i=0;i<n;i++)
  {
    cin>>c;
    insert(&inptr,c);
  }
  treenode *root=construct(inptr,postptr,n);
  postorder(root);
  return 0;
}
