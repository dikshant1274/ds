#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
class queue
{
  node *rear;
public:
  queue()
  {
    rear=NULL;
  }
  void insert(int x)
  {
    node *temp=new node;
    if(temp==NULL)
    {
      cout<<"memory overflow"<<endl;
      return;
    }
    temp->data=x;
  if(rear==NULL)
  {
    rear=temp;
    temp->next=rear;
  }
  else
  {
    temp->next=rear->next;
    rear->next=temp;
    rear=temp;
  }

  }
  int del()
  {
      node *temp;
    if(rear==NULL)
    {
      cout<<"queue underflow"<<endl;
      return 0;
    }
    if(rear==rear->next)
    {
      temp=rear;
      rear=NULL;
    }
    else
    {
      node *temp=rear->next;
      rear->next=rear->next->next;
    }
    return temp->data;
  }
  void disp()
  {
    node *temp=rear->next;
  do
  {
    /* code */
    cout<<temp->data<<endl;
    temp=temp->next;
  } while(temp!=rear->next);
  }
};
int main()
{
  queue q;
  q.insert(5);
  q.insert(10);
  q.insert(15);
  q.del();
  q.del();
  q.insert(20);
  q.insert(25);

  q.del();
  q.disp();
}
