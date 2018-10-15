#include<iostream>
#include<stack>
using namespace std;
int valid(string s)
{
  stack<char> c;
  int count=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='(')
    {
      c.push(s[i]);
    }
    else
    {
      if(c.empty())
      {

      }
      else
      {
        if(c.top()=='(')
        {
          c.pop();
          count+=2;
        }
      }
    }
  }
  return count;
}
int main()
{
  string s;
  cin>>s;
  int x=valid(s);
  cout<<x<<endl;
}
