#include<iostream>
using namespace std;
void insertionsort(int arr[],int x)
{
  int j,key;
  for(int i=1;i<x;i++)
  {
    j=i-1;
    key=arr[i];
    while(j>=0&&arr[j]>key)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
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
  for(int j=0;j<n;j++)
  {
    cout<<arr[j]<<endl;
  }

}
