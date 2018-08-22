#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
class queue
{
  node *front,*rear;
public:
  queue()
  {
    front=NULL;
    rear=NULL;
  }
  void enqueue(int data)
  {
    node *temp=new node;
    temp->data=data;
    if(rear==NULL)
    {
      temp->next=NULL;
      rear=temp;
      front=rear;
    }
    else
    {
      temp->next=rear->next;
      rear->next=temp;
      rear=temp;
    }
  }
  void deque()
  {
    if(front==NULL)
    {
      cout<<"queue underflow"<<endl;
    }
    else
    {
      node *temp=front;
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
  queue q;
  q.enqueue(6);
  q.enqueue(5);
  q.enqueue(8);
  q.enqueue(10);
  q.enqueue(11);
  q.deque();
  q.display();
  return 0;

}
