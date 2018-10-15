#include<iostream>
using namespace std;
void selectionsort(int arr[],int x)
{
    int j;
    int temp;
    for(int i=0;i<x;i++)
    {
        int min=i;
        for(j=i+1;j<x;j++)
        {
          if(arr[j]<arr[min])
          {
            min=j;
          }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
  for(int j=0;j<n;j++)
  {
    cout<<arr[j]<<endl;
  }

}
