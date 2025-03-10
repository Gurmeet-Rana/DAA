#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void countSort(int arr[],int n,int i)
{
    int maxElement=INT_MIN;
    for(int i=0;i<n;i++)
    vector<int> frq(n,0);
}

int main()
{
    int n;
    cout<<"Enter the size of the vector : "<<endl;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int maxElement=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxElement=max(arr[i],maxElement);
    }

    int i=1;
    while(maxElement/i>0)
    {
        countSort(arr,n,i);
        i*=10;
    }

    return 0;
}