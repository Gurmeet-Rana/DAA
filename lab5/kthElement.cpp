/* Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n)) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findKthSmallest(vector<int> &v,int n,int k)
{
    if(k+1>n)
    {
        cout<<k<<"th Smallest Element does not exists !"<<endl;
        return -1;
    }
    return v[k+1];
}

int findKthLargest(vector<int> &v,int n,int k)
{
    if(k+1>n)
    {
        cout<<k<<"th Largest Element does not exists !"<<endl;
        return -1;
    }
    return v[n-k+1];
}

void countSort(vector<int> &v,int n)
{
    int maxEle=*max_element(v.begin(),v.end());
    int minEle=*min_element(v.begin(),v.end());

    int frqSize=maxEle+1;
    if(minEle<0)
    {
        frqSize-=minEle;
    }

    cout<<"Size of frequency array is : "<<frqSize<<endl;

    vector<int> frq(frqSize,0);

    for(int i=0;i<n;i++)
    {
        if(minEle< 0)
        {
            frq[v[i]-minEle]++;
        }
        else
        {
            frq[v[i]]++;
        }        
    }

    for(int i=1;i<frqSize;i++)
    {
        frq[i]+=frq[i-1];
    }

     
    vector<int> res(n);
    for(int i=n-1;i>=0;i--)
    {
        
        int indx=--frq[v[i]-minEle];      

        res[indx]=v[i];
    }

    for(auto num:res) cout<<num<<" ";
    cout<<endl;

     

}


int main()
{
    int testCases=0;
    cout<<"Enter the number of test Cases : "<<endl;
    cin>>testCases;
    while (testCases--)
    {
        int n;
        cout<<"Enter the size of the array : "<<endl;
        cin>>n;
        cout<<"Enter the values in the array : "<<endl;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int k;
        cout<<"Enter the value of k : "<<endl;
        cin>>k;

        countSort(v,n);
        int small=findKthSmallest(v,n,k);
        if(small!=-1)
        {
            cout<<k<<"th Smallest element is : "<<small<<endl;
        }
        int large=findKthLargest(v,n,k);
        if(large!=-1)
        {
            cout<<k<<"th Largest element is : "<<large<<endl;
        }
    }
    
    return 0;
}