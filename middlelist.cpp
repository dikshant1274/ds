#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
void insert(node **head,int data)
{
  node *temp=new node;
  if(*head==NULL)
  {
    temp->data=data;
    temp->next=*head;
    *head=temp;
  }
  else
  {
    temp->data=data;
    temp->next=*head;
    *head=temp;
  }

node* middle(node **head)
{
  node *temp1=*head;
  node *temp2=*head;
  
}
int main()
{
  node *head=NULL;
  int n,i,val;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>val;
    insert(&head,val);
  }


}
