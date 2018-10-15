#include<iostream>
using namespace std;
#define MAX 7
class deque
{
  int front,rear,arr[MAX];
public:
  deque()
  {
    front=-1;
    rear=-1;
  }
  void insertatfront(int x)
  {
    if(front==0 && rear==MAX-1||front==rear+1)
    {
      cout<<"queue overflow"<<endl;
    }
    else if(front==-1)
    {
      front++;
      rear++;
      arr[front]=x;
    }
    else if(front==0)
    {
      front=MAX-1;
      arr[front]=x;
    }
    else
    {
      front--;
      arr[front]=x;
    }
  }
  void insertatend(int x)
  {
  if(front==0 && rear==MAX-1||front==rear+1)
  {
    cout<<"queue overflow"<<endl;
  }
  else if(front==-1)
  {
    front++;
    rear++;
    arr[rear]=x;
  }
  else if(rear==MAX-1)
  {
    rear=0;
    arr[rear]=x;
  }
  else
  {
    rear++;
    arr[rear]=x;
  }


  }
  void deleteatfront()
  {
    if(front==-1)
    {
      cout<<"queue underflow"<<endl;
    }
    else if(front==MAX-1)
    {
      front=0;
    }
    else if(front==rear)
    {
      front=rear=-1;
    }
    else
    {
      front++;
    }
  }
  void deleteatend()
  {
    if(front==-1)
    {
      cout<<"queue underflow"<<endl;
    }
    else if(rear==0)
    {
      rear=MAX-1;
    }
    else if(front==rear)
    {
      front=rear=-1;
    }
    else
    {
      rear--;
    }
  }
  void display()
  {
    int i;
    if(front>rear)
    {
      for(i=front;i<MAX;i++)
      {
        cout<<arr[i]<<endl;
      }
      for(i=0;i<=rear;i++)
      {
        cout<<arr[i]<<endl;
      }
    }
    else
    {
      for(i=front;i<=rear;i++)
      {
        cout<<arr[i]<<endl;
      }
    }
  }
};
int main()
{
    deque d;
    d.insertatfront(20);
    d.insertatfront(30);
    d.insertatend(40);
    d.deleteatend();
    d.deleteatfront();
d.display();
}
