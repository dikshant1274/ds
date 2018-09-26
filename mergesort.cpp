#include<iostream>
using namespace std;
void merge(int *arr,int l,int m,int r)
{
  int n1=m-l+1;
  int n2=r-m;
  int l1[n1],r1[n2];
  for(int i=0;i<n1;i++)
  {
    l1[i]=arr[l+i];
  }
  for(int j=0;j<n2;j++)
  {
    r1[j]=arr[m+1+j];
  }
int  i=0;
int  j=0;
  int k=l;
  while(i<n1&&j<n2)
  {
    if(l1[i]<r1[j])
    {
      arr[k]=l1[i];
      i++;
    }
    else
    {
      arr[k]=r1[j];
      j++;
    }
    k++;
  }
while(i<n1)
{
  arr[k]=l1[i];
  i++;
  k++;
}
while(j<n2)
{
  arr[k]=r1[j];
  j++;
  k++;
}
}
void mergesort(int *arr,int l,int r)
{

  if(l<r)
  {
      int m=(l+r)/2;
      mergesort(arr,l,m);
      mergesort(arr,m+1,r);
      merge(arr,l,m,r);
  }
}
int main()
{
  int n;
  cin>>n;
  int *arr=new int[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  mergesort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<endl;
  }
}
