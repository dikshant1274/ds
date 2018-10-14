#include<iostream>
using namespace std;
struct node
{
  node *left;
  int data;
  node *right;
};
void insert(node **root,int key)
{
  node *ptr=*root;
  node *par=NULL;
  while(ptr!=NULL)
  {
    par=ptr;
    if(key<ptr->data)
    ptr=ptr->left;
    else if(key>ptr->data)
    ptr=ptr->right;
    else
    {
      cout<<"duplicate keys not allowed"<<endl;
      break;
    }
  }
  node *temp=new node;
  temp->data=key; 
  temp->left=NULL;
  temp->right=NULL;
  if(par==NULL)
  {
    *root=temp;
    return;
  }
  if(key<par->data)
  par->left=temp;
  else
  par->right=temp;
}
void inorder(node *root)
{
  if(root==NULL)
  {
    return;
  }

  inorder(root->left);
    cout<<root->data<<" ";
  inorder(root->right);
}
int main()
{
  node *root=NULL;
  int n,key;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>key;
    insert(&root,key);
  }
  inorder(root);
return 0;
}
