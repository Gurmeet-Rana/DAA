/* Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array. */

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v,int low,int mid,int high,vector<int> &inver,int &cmp)
{
    int n1=mid-low+1,n2=high-mid;
    int i=0,j=0;
    vector<int> ans(n1+n2);
    int k=0;
    while(i<n1 && j<n2)
    {
        cmp++;
        if(v[low+i]<v[j+mid+1])
        {
            ans[k]=v[i+low];
            k++;
            i++;
        }        
        else{
            inver.push_back(v[j+1+mid]);
            ans[k]=v[j+1+mid];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        ans[k]=v[i+low];
        k++;
        i++;
    }
    while(j<n2)
    {
        ans[k]=v[j+1+mid];
        k++;
        j++;
    }

    for(int indx=0;indx<ans.size();indx++)
    {
        v[indx+low]=ans[indx];
    }
}

void mergeSort(vector<int> &v,int low,int high,vector<int> &inver,int &cmp)
{
    if(low>=high) return ;
    int mid=low+(high-low)/2;
    mergeSort(v,low,mid,inver,cmp);
    mergeSort(v,mid+1,high,inver,cmp);
    merge(v,low,mid,high,inver,cmp);
}

int main()
{
    int testCases=0;
    cout<<"Enter the number of test cases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of the vector : "<<endl;
        cin>>n;
        vector<int> v(n,0);
        cout<<"Enter the values in the vector : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        vector<int> inversions;
        int comparisons=0;
        mergeSort(v,0,n-1,inversions,comparisons);
        cout<<"Sorted vector :"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparisons done : "<<comparisons<<endl;
        if(inversions.empty())
        {
            cout<<"No Inversions !"<<endl;
        }
        else{
            cout<<"Inversions : "<<endl;
            for(auto i:inversions) cout<<i<<" ";
            cout<<endl; 
        }
    }
    return 0;
}