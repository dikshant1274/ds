#include<iostream>
using namespace std;
#define MAX 5
class queue
{
  int front,rear,arr[MAX];
public:
  queue()
  {
    front=-1;
    rear=-1;
  }
  void insert(int x)
  {
    if(rear==MAX-1)
    {
      cout<<"queue overflow"<<endl;
    }
    else if(front==-1&&rear==-1)
    {
      front++;
      rear++;
      arr[rear]=x;
    }
    else
    {
      rear++;
      arr[rear]=x;
    }
  }
  void del()
  {
    if(front==rear+1||front==-1)
    {
      cout<<"queue underflow"<<endl;
    }
    else
    {
      front++;
    }
  }
  void disp()
  {
    int i;
    for(i=front;i<=rear;i++)
    {
      cout<<arr[i]<<endl;
    }
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
  q.del();
  q.insert(20);
  q.insert(25);
  q.disp();
}
