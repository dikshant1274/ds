#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100
class stack
{
  int top;
  char a[MAX];
public:
  stack()
  {
    top=-1;
  }
  void push(char x)
  {
    a[++top]=x;
  }
  void pop()
  {
    cout<<a[top--];
  }


};
int main()
{
  char str[MAX];
  int i=0;
  stack ob;
  cin>>str;
  int len=strlen(str);
  while(i<len)
  {
    ob.push(str[i]);
    i++;
  }

  while(len>0)
  {
    ob.pop();
    len--;
  }
  return 0;
}
