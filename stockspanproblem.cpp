#include<iostream>
#include<stack>
using namespace std;
void span(int *a,int *s,int n)
{
  stack<int> st;
  s[0]=1;
  st.push(0);
  for(int i=1;i<n;i++)
  {
    while(!st.empty()&&a[st.top()]<=a[i])
    {
      st.pop();
    }
    s[i]=st.empty()?i+1:i-st.top();
    st.push(i);
  }
}
int main()
{
  int n;
  cin>>n;
  int *arr=new int[n];
  int *s=new int[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  span(arr,s,n);
  for(int i=0;i<n;i++)
  cout<<s[i]<<endl;
}
