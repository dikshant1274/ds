#include<iostream>
#include<stack>
using namespace std;
bool balance(string exp)
{
  int i;
  stack<char> s;
  for(i=0;i<exp.length();i++)
  {
    if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
    {
      s.push(exp[i]);
      continue;
    }
    if(s.empty())
    {
      return false;
    }
    switch(exp[i])
    {
      case ')':
      {
        char x=s.top();
        s.pop();
        if(x=='{'||x=='[')
        {
          return false;

        }
          break;
      }
      case '}':
      {
        char x=s.top();
        s.pop();
        if(x=='('||x=='[')
        {
          return false;

        }
          break;
      }
      case ']':
      {
        char x=s.top();
        s.pop();
        if(x=='{'||x=='(')
        {
          return false;

        }
          break;
      }
    }


  }
  return (s.empty());
}
int main()
{
  string p;
  cin>>p;
  bool x=balance(p);
  if(x==true)
  {
    cout<<"balanced";
  }
  else
  {
    cout<<"unblanced";
  }
  return 0;
}
