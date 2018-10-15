#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
  node *prev;
};
class deque
{
 node *front,*rear;
public:
  deque()
  {
    front=NULL;
    rear=NULL;
  }
  void insertatfront(int x)
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
      temp->prev=front;
      front=temp;
      rear=temp;

    }
    else
    {
      front->prev=temp;
      temp->next=front;
      temp->prev=NULL;
      front=temp;
    }

  }
  void insertatend(int x)
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
      temp->prev=front;
      front=temp;
      rear=temp;
    }
    else
    {
      temp->next=rear->next;
      rear->next=temp;
      temp->prev=rear;
      rear=temp;
    }
  }
  int  deleteatfront()
  {
    int x;
    if(front==NULL)
    {
      cout<<"queue underflow"<<endl;
    }
    else if(front==rear)
    {
      x=front->data;
      front=NULL;
      rear=NULL;
    }
    else
    {
      x=front->data;
      front=front->next;
      front->prev=NULL;
    }
    return x;
  }
  int deleteatend()
  {
    int x;
    if(front==NULL)
    {
      cout<<"queue underflow"<<endl;
    }
    else if(front==rear)
    {
      x=front->data;
      front=rear=NULL;
    }
    else
    {
      x=rear->data;
      rear=rear->prev;
      rear->next=NULL;
    }
    return x;
  }
  void display()
  {
    node *temp;
    for(temp=front;temp!=NULL;temp=temp->next)
    {
      cout<<temp->data<<endl;
    }
  }
};
int main()
{
  deque d;
  d.insertatfront(10);
  d.insertatfront(20);
  d.insertatfront(30);
  d.insertatend(40);
  d.deleteatfront();
  d.deleteatend();
  d.insertatfront(10);
  d.insertatfront(20);
  d.insertatfront(30);
  d.display();
}
