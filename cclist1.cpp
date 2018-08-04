#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
void insertatbeg(node **last,int data)
{
  node *temp=new node;
  temp->data=data;
  if(*last==NULL)
  {
    *last=temp;
    temp->next=*last;
  }
  else
  {
    temp->next=(*last)->next;
    (*last)->next=temp;
  }
}
void insertatend(node **last,int data)
{
  node *temp=new node;
  temp->data=data;
  if(*last==NULL)
  {
    *last=temp;
    temp->next=temp;
  }
  else
  {
    temp->next=(*last)->next;
    (*last)->next=temp;
    (*last)=temp;
  }
}
void insertafternode(node *last,int data)
{
  node *temp=new node;
  temp->data=data;
  temp->next=last->next;
  last->next=temp;
}
void display(node *last)
{
  node *temp=last;
  do {
    /* code */
    cout<<temp->data<<endl;
    temp=temp->next;
  } while(temp!=last);
}
int main()
{
  node *last=NULL;
  insertatend(&last,12);
  insertatbeg(&last,14);
  insertatend(&last,15);
  insertafternode(last->next->next,89);
  display(last->next);

}
