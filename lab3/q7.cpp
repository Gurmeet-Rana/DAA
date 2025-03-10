/* Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts 
total number of times the array elements are shifted from their place) required for sorting the
array. */

#include<iostream>
using namespace std;
class Solution
{
    public : 
        void insertionSort(int arr[],int n,int &shifts,int &comparisons)
        {
             
            for(int i=1;i<n;i++)
            {
                int j=i-1;
                int key=arr[i];
                while(j>=0 && arr[j]>key)
                {
                    comparisons++; 
                    arr[j+1]=arr[j];
                    shifts++;
                    j--;
                }

                if(j>=0)
                {
                    comparisons++;
                }
                 
                arr[j+1]=key;
                 
            }
             
        } 
};
int main()
{
    int testCases;
    cout<<"Enter the number of testcases : "<<endl;
    cin>>testCases;
    Solution obj;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of the array : "<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the values in the array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        } 
        int comparisons=0,shifts=0;
        obj.insertionSort(arr,n,comparisons,shifts);
        cout<<"The sorted array is : "<<endl;
        for(auto num:arr)
        {
            cout<<num<<" ";
        }
        cout<<endl;
        cout<<"Number of comparisons needed : "<<comparisons<<endl;
        cout<<"Number of shifts needed : "<<shifts<<endl;

    } 
}