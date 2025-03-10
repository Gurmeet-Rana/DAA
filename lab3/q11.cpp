/* Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array */
#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> &v,int low,int high,int &swaps,int &cmp)
{
    int pivotIndx=rand()%(high-low+1)+low;

    swap(v[pivotIndx],v[high]);
    swaps++;

    int key=v[high];
    int i=low-1,j=low;
    while(j<high)
    {
        cmp++;
        if(v[j]<=key)
        {
            swaps++;
            i++;
            swap(v[j],v[i]);
        }
        j++;
        
    }
    swaps++;
    swap(v[i+1],v[high]);
    return i+1;
}

void quickSort(vector<int> &v,int low,int high,int &swaps,int &cmp)
{
    if(low>=high) return ;
    int pivot=findPivot(v,low,high,swaps,cmp);
    quickSort(v,low,pivot-1,swaps,cmp);
    quickSort(v,pivot+1,high,swaps,cmp);
}

int main()
{
    int testCases=0;
    cout<<"Enter the number of test Cases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of the vector : "<<endl;
        cin>>n;
        vector<int> v(n);
        cout<<"Enter the values in the vector : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int swaps=0,cmp=0;
        quickSort(v,0,n-1,swaps,cmp);
        cout<<"The Sorted array is : "<<endl;
        for(auto n:v) cout<<n<<" ";
        cout<<endl;
        cout<<"Swaps done : "<<swaps<<endl;
        cout<<"Comparisons done : "<<cmp<<endl;
        
    }
    return 0;
} 