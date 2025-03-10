/* Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n) */

#include<iostream>
using namespace std;
class Solution
{
    public : 
        int lowerBound(int arr[],int n,int key)
        {
            int indx=-1,left=0,right=n-1;
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(arr[mid]>=key)
                {
                    indx=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            return indx;
        }
        int upperBound(int arr[],int n,int key)
        {
            int indx=-1,left=0,right=n-1;
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(arr[mid]<=key)
                {
                    indx=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            return indx;
        }
};

int main()
{
    int testCases;
    cout<<"Enter the number of test cases : "<<endl;
    cin>>testCases;
    Solution obj;
    int n;
        cout<<"Enter the size of the vector "<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the values in the array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    while(testCases--)
    {
        
        int key;
        cout<<"Enter the key element to search for : "<<endl;
        cin>>key;
        int leftIndex=obj.lowerBound(arr,n,key);
        int rightIndex=obj.upperBound(arr,n,key);
        int occurences=rightIndex-leftIndex+1;
        if(occurences==0)
        {
            cout<<"Key element not found"<<endl;
        }
        else
        {
            cout<<"Key element found at index "<<leftIndex<<" and occurence is "<<occurences<<endl;
        }
    }
    return 0;
}