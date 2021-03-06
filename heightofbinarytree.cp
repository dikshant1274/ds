#include<iostream>
using namespace std;
struct node
{
  int data;
  node *right;
  node *left;
};
node* newnode(int data)
{
  node *temp=new node;
  temp->data=data;
  temp->right=NULL;
  temp->left=NULL;
  return temp;
}
int height(node *root)
{
  int h_left,h_right;
  if(root==NULL)
  return 0;
  h_left=height(root->left);
  h_right=height(root->right);
  if(h_left>h_right)
  return h_left+1;
  else
  return h_right+1;
}
void inorder(node *root)
{
  if(root==NULL)
   return ;
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}
int main()
{
  node *root=newnode(10);
  root->left=newnode(12);
  root->left->left=newnode(13);
  root->left->right=newnode(14);
  root->right=newnode(15);
  root->right->left=newnode(16);
  cout<<height(root)<<endl;
}
