/* Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n)) */

#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> &v,int low,int high)
{
    int pivot=v[high];

    int i=low-1;
    int j=low;
    while(j<high)
    {
        if(v[j]<=pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[high]);
    return i+1;
}

void quickSort(vector<int> &v,int low,int high,const int& k,int& ans)
{
    if(low>=high  || k<low || k>high ) return ;
    int pivot=findPivot(v,low,high);
    if(pivot+1==k)
    {
        ans=v[pivot];
        return ;
    }
    if(pivot<k)
    {
        quickSort(v,low,pivot-1,k,ans);
    }
    else
    {
        quickSort(v,pivot+1,high,k,ans);
    }

}

int main()
{
    int testCases=0;
    cout<<"Enter the number of testCases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of the vector : "<<endl;
        cin>>n;
        cout<<"Enter the values in the vector : "<<endl;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int k;
        cout<<"Enter the value of k : "<<endl;
        cin>>k;

        int smallest;
        quickSort(v,0,n-1,k,smallest);

        cout<<k<<"th Smallest element in the array is : "<<smallest<<endl;

        int largest;
        quickSort(v,0,n-1,n-k+1,largest);

        cout<<k<<"th Largest element in the array is :"<<largest<<endl;


    }
    return 0;
}