#include<iostream>
#include<stack>
using namespace std;
void deletemed(stack<int> &st,int n,int temp=0)
{
  if(st.empty()||temp==n)
  {
    return ;
  }
  int x=st.top();
  st.pop();
  deletemed(st,n,temp+1);
  if(temp!=n/2)
  {
    st.push(x);
  }

}
int main()
{
  stack<int> st;
  int n,val;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>val;
    st.push(val);
  }
  deletemed(st,n);
  while(!st.empty())
  {
    cout<<st.top()<<endl;
    st.pop();
  }
  return 0;
}
