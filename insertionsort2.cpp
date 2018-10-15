#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
  int key;
  for(int i=1;i<n;i++)
  {
    key=arr[i];
  int  j=i-1;
    while(j>=0&&arr[j]>key)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
}
void display(int *arr,int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<endl;
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
  insertionsort(arr,n);
  display(arr,n);
  return 0;
}
