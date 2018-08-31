#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
class cirqueue
{
  node *front,*rear;
public:
  cirqueue()
  {
    front=NULL;
    rear=NULL;
  }
  void enqueue(int x)
  {
    node *temp=new node;
    temp->data=x;
    if(temp==NULL)
    {
      cout<<"queue overflow"<<endl;
    }
    else if(front==NULL)
    {
      temp->next=front;
      front=temp;
      rear=temp;
    }
    else
    {
      temp->next=rear->next;
      rear->next=temp;
      rear=temp;
    }
  }
  void dequeue()
  {
    if(front==NULL)
    {
      cout<<"queue underflow"<<endl;
    }
    else
    {
      front=front->next;
    }
  }
  void display()
  {
    node *temp=front;
    while(temp!=NULL)
    {
      cout<<temp->data<<endl;
      temp=temp->next;
    }
  }
};
int main()
{
  cirqueue c;
  c.enqueue(10);
  c.enqueue(20);
  c.enqueue(30);
  c.enqueue(40);
  c.dequeue();
  c.dequeue();
  c.display();
  return 0;
}
