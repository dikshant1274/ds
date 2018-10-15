#include<iostream>
#include<stack>
using namespace std;
int prec(char a)
{
  switch (a) {
    case '^':
    {
      return 3;
    }
    case '*':
    case '/':
    {
      return 2;
    }
    case '+':
    case '-':
    {
      return 1;
    }
    default:
    return -1;
  }
}
int main()
{
  stack<char> st;
  st.push('N');
  string s,outs;
  cin>>s;
  int i;
  for(i=0;i<s.length();i++)
  {
    if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
    {
      outs+=s[i];
    }
    else if(s[i]=='(')
    {
      st.push(s[i]);
    }
    else if(s[i]==')')
    {
      while(st.top()!='N'&& st.top()!='(')
      {
        char c=st.top();
        st.pop();
        outs+=c;

      }
      if(st.top()=='(')
      {
        char c=st.top();
        st.pop();
      }

    }
    else
    {
      while(st.top()!='N'&&prec(s[i])<=prec(st.top()))
      {
        char c=st.top();
        st.pop();
        outs+=c;
      }
      st.push(s[i]);
    }
  }
  while(st.top()!='N')
  {
    char c=st.top();
    st.pop();
    outs+=c;
  }

  cout<<outs<<endl;
}
