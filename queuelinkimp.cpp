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
  void insert(int x)
  {
    node *temp=new node;
    if(temp==NULL)
    {
      cout<<"memory not available"<<endl;
      return ;
    }
    temp->data=x;
    if(front==NULL)
    {
      temp->next=front;
      front=temp;
      rear=temp;
    }
    rear->next=temp;
    rear=temp;

  }
  int  del()
  {
    if(front==NULL)
    {
      cout<<"queue underflow"<<endl;
      return 0;
    }
    node *temp=front;
    front=front->next;
    return temp->data;
  }
  void disp()
  {
    node *temp=front;
    while(temp!=rear->next)
    {
      cout<<temp->data<<endl;
      temp=temp->next;
    }
  }
};
int main()
{
  queue q;
  q.insert(10);
  q.insert(20);
  q.insert(30);
  q.insert(40);
  int c=q.del();

  q.disp();
}
