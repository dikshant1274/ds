#include<iostream>
#include<stack>
using namespace std;
stack<int> sort(stack<int> &s)
{
  stack<int> temp;
  int x;
  while(!s.empty())
  {
    x=s.top();
    s.pop();
    while(!temp.empty()&&x<temp.top())
    {
      s.push(temp.top());
      temp.pop();
    }
    temp.push(x);
  }
  return temp;
}
int main()
{
  stack<int> s;
  int n,val;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>val;
    s.push(val);
  }
stack<int> c=sort(s);
while(!c.empty())
{
  cout<<c.top()<<endl;
  c.pop();
}
}
