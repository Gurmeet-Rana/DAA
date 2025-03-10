#include<iostream>
#include<algorithm>
using namespace std;
int findPivot(int arr[],int left,int right)
{
    int i=left-1;  // J WILL POINT TO THE GREATERS AND I WILL POINT TO THE SMALLER
    int pivotEle=arr[right];
    int j=left;
    for(;j<right;j++)
    {
        if(arr[j]<pivotEle)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[right]);
    return i;
}
void quickSort(int arr[],int i,int j)
{
    if(i>=j) return ;
    int pivotIndex=findPivot(arr,i,j);
    quickSort(arr,i,pivotIndex-1);
    quickSort(arr,pivotIndex+1,j);
    
}
int main()
{
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the values in the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"The sorted array is : "<<endl;
    for(auto n:arr) cout<<n<<" ";
    return 0;
}