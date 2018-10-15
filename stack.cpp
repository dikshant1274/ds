#include<iostream>
using namespace std;
#define MAX 100
class stack
{
int top;
int a[MAX];
public:
  stack()
  {
    top=-1;
  }
  bool push(int x)
  {
    if(top>=MAX-1)
    {
      cout<<"stack overflow"<<endl;
      return true;
    }
    else
    {
        a[++top]=x;
        return true;
    }
  }
  int pop()
  {
    int x;
    if(top<0)
    {
      cout<<"stack underflow"<<endl;
      return 0;
    }
    else
    {
      x=a[top--];
      return x;
    }
  }
  bool isempty()
  {
    return(top<0);
  }
  int peak()
  {
    return a[top];
  }
  void display()
  {
    int i;
    for(i=top;i>=0;i--)
    {
      cout<<a[i]<<endl;
    }
  }
};
int main()
{
  stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.pop();
  s.display();
}
