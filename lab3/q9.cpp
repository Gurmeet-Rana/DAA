/* Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n)) */

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v,int low,int mid,int high)
{
    int n1=mid-low+1,n2=high-mid;

    vector<int> v1(n1,0),v2(n2);
    for(int i=0;i<n1;i++)
    {
        v1[i]=v[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        v2[j]=v[j+mid+1];
    }
    
    int i=0,j=0,k=low;
    
    while(i<n1 && j<n2)
    {   
        if(v1[i]<v2[j])
        {
            v[k]=v1[i];
            i++;
            k++;
        }
        else if(v2[j]<v1[i])
        {
            v[k]=v2[j];
            k++;
            j++;
        }
        else
        {
            v[k]=v1[i];
            k++;
            i++;
        }
    }
    while(i<n1)
    {
        v[k]=v1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        v[k]=v2[j];
        k++;
        j++;
    }
}
void mergeSort(vector<int> &v,int low,int high)
{
    if(low>=high) return ;
    int mid=low+(high-low)/2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1,high);
    merge(v,low,mid,high); 
}
int main()
{
    int testCases;
    cout<<"Enter the number of test cases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of the array : "<<endl;
        cin>>n;
        vector<int> v(n,0);
        cout<<"Enter the values in the array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        mergeSort(v,0,v.size()-1);
        bool flag=false;

        cout<<"The sorted array is : "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;

        for(int i=1;i<n;i++)
        {
            if(v[i]==v[i-1])
            {
                flag=true;
                cout<<v[i]<<" Is the duplicate element !! "<<endl;
            }
        }
        if(!flag)
        {
            cout<<"No duplicate element is there !"<<endl;
        }
    }
    return 0;
}

//1508 , 1488 , 1439 , 1348 , 1292 , 902;