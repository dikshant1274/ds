#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
void push(node **root,int data)
{
   node *temp=new node;
   if(*root==NULL)
   {
     temp->data=data;
     temp->next=*root;
     *root=temp;
   }
   else
   {
     temp->data=data;
     temp->next=*root;
     *root=temp;
   }
}
bool isempty(node *root)
{
  if(root==NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int pop(node **root)
{
  if(*root==NULL)
  {
    cout<<"stack underflow"<<endl;
    return 0;
  }
  node *temp=*root;
  (*root)=(*root)->next;
  return temp->data;
}
int top(node **root)
{
  if(*root==NULL)
  {
    return -1;
  }
  else
  {
  return (*root)->data;
  }
}
void display(node *root)
{
  while(root!=NULL)
  {
    cout<<root->data<<endl;
    root=root->next;
  }
}
int main()
{
  node *root=NULL;
  push(&root,10);
  push(&root,20);
  push(&root,30);
  pop(&root);
cout<<  top(&root)<<endl;
  display(root);
}
