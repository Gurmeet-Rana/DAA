#include<iostream>
using namespace std;
void merge(int arr[],int st,int mid,int end)
{
    int n=mid-st+1,m=end-mid;
    int temp[n+m];
    int i=st,j=mid+1,k=0;
    while(i<=mid && j<=end) 
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=end)
    {
        temp[k++]=arr[j++];
    }

    for(int i=0;i<n+m;i++)
    {
        arr[i+st]=temp[i];
    }

}
void mergeSort(int arr[],int st,int end)
{
    if(st>=end) return ;
    int mid=st+(end-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,mid,end);
}
int main()
{
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter values in the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted array is : "<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
} 