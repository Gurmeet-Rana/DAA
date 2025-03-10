/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching) */

#include<iostream>
using namespace std;
class Solution
{
        int linearSearch(int arr[],int st,int end,int val)
        {
            for(int i=st;i<=end;i++)
            {
                if(arr[i]==val)
                {
                    return i;
                }
            }
            return -1;
        }
    public:
        int searchElement(int arr[],int n,int key,int windowSize)
        {
            int i=0,j=windowSize-1;
            int op=0;
            while(j<n) 
            {
                op++;
                if(key>arr[j])
                {
                    i=j+1;
                    j+=windowSize;
                }
                else{
                    op+=linearSearch(arr,i,j,key);
                    return op;
                }
            }
            int indx=linearSearch(arr,i,n-1,key);
            if(indx==-1)
            {
                return -1;
            }
            return op+indx;
        }
};
int main()
{
    int testCases;
    cout<<"Enter the number of test cases : "<<endl;
    cin>>testCases;
    Solution obj;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of the vector"<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the values in the array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int key;
        cout<<"Enter the key element to search for : "<<endl;
        cin>>key;
        int windowSize;
        cout<<"Enter the window size : "<<endl;
        cin>>windowSize;
        int op=obj.searchElement(arr,n,key,windowSize);
        if(op==-1)
        {
            cout<<key<<" is not present in the array . "<<endl;
        }
        else
        {
            cout<<key<<" is present . Total comparisons needed = "<<op<<endl;
        }
    }
    return 0;
} 