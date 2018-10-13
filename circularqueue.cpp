#include<iostream>
using namespace std;
#define MAX 7
class cirqueue
{
  int front,rear,arr[MAX];
public:
  cirqueue()
  {
    front=-1;
    rear=-1;
  }
  void enqueue(int x)
  {
    if(front==0&&rear==MAX-1||front==rear+1)
    {
      cout<<"queue overflow"<<endl;
      return;
    }
    if(front==-1)
    {
      front++;
      rear++;
      arr[rear]=x;
    }
    else if(rear==MAX-1&& front!=0)
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
  int deque()
  {
    int x;
    if(front==-1)
    {
      cout<<"queue underflow"<<endl;
    }
    else if(front==MAX-1)
    {
      x=front;
      front=0;
    }
    else if(front==rear)
    {
      x=front;
      front=-1;
      rear=-1;
    }
    else
    {
      x=front;
      front++;
    }
    return x;
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
  cirqueue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();
  return 0;
}
