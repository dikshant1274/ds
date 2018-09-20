#include<iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
  int min,temp;
  for(int i=0;i<n;i++)
  {
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(arr[min]>arr[j])
      {
        min=j;
      }
    }
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
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
  selectionsort(arr,n);
  display(arr,n);
}
