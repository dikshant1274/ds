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
node* case_a(node *root,node *par,node *ptr)
{
  if(par==NULL)
  root=NULL;
  else if(ptr==par->left)
  par->left=NULL;
  else
  par->right=NULL;
  return root;
}
node* case_b(node *root,node *par,node *ptr)
{
  node *child;
  if(ptr->left!=NULL)
  child=ptr->left;
  else
  child=ptr->right;
  if(par==NULL)
  root=child;
  else if(ptr==par->left)
  par->left=child;
  else
  par->right=child;
  return root;
}
node* case_c(node *root,node *par,node *ptr)
{
  node *parsucc,*succ;
  parsucc=ptr;
  succ=ptr->right;
  while(succ->left!=NULL)
  {
    parsucc=succ;
    succ=succ->left;
  }
  ptr->data=succ->data;
  if(succ->left==NULL&&succ->right==NULL)
  case_a(root,parsucc,succ);
  else
  case_b(root,parsucc,succ);
  return root;
}
node* deletenode(node *root,int key)
{
  node *ptr=root;
  node *par=NULL;
  if(ptr==NULL)
  return NULL;
  while(ptr!=NULL)
  {
    if(key==ptr->data)
     break;
     par=ptr;
      if(key<ptr->data)
     ptr=ptr->left;
     else
     ptr=ptr->right;
  }
  if(ptr->left!=NULL&&ptr->right!=NULL)
  root=case_c(root,par,ptr);
  else if(ptr->left!=NULL)
  root=case_b(root,par,ptr);
  else if(ptr->right!=NULL)
  root=case_b(root,par,ptr);
  else
  root=case_a(root,par,ptr);
  return root;
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
  while(1)
  {
    cin>>key;
    if(key==0)
    {
      break;
    }
    deletenode(root,key);
  }
  inorder(root);
return 0;
}
