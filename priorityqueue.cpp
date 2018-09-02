#include<iostream>
using namespace std;
struct node
{
  int priority;
  int data;
  node *next;
};
class  pqueue
{
  node *front,*rear;
public:
  pqueue()
  {
    front=NULL;
  }
  void enqueue(int x,int p)
  {
    node *temp=new node;
    if(temp==NULL)
    {
      cout<<"queue overflow"<<endl;
      return;
    }
    temp->data=x;
    temp->priority=p;
    if(front==NULL)
    {
      temp->next=front;
      front=temp;
    }
    else
    {
      if(p<front->priority)
      {
        temp->next=front;
        front=temp;
      }
      else
      {
        node *temp1=front;
        while(temp1->next!=NULL&&p>=temp1->next->priority)
        {
          temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
      }
    }
  }
  int del()
  {
    int x;
    if(front==NULL)
    {
      cout<<"queue underflow"<<endl;
      return 0;
    }
    else
    {
      x=front->data;
      front=front->next;
    }
    return x;
  }
  void disp()
  {
    node *temp=front;
    while(temp!=NULL)
    {
      cout<<temp->priority<<" "<<temp->data<<endl;
      temp=temp->next;
    }
  }

};
int main()
{
  pqueue p;
  p.enqueue(12,4);
  p.enqueue(14,1);
  p.enqueue(18,1);
  p.enqueue(15,3);
  p.enqueue(56,2);
  p.del();
  p.disp();
  return 0;
}
