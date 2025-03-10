/* Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required */
#include<iostream> 
using namespace std;
class Solution
{
    public :
    void selectionSort(int arr[],int n,int &comparisons,int &swaps)
    {
         for(int i=0;i<n;i++)
         {
            int minIndex=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[minIndex])
                {
                    comparisons++;
                    minIndex=j;
                }
            }
            if(i!=minIndex)
            {
                swaps++;
                swap(arr[i],arr[minIndex]);
            }
         }
    }
};
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
        int arr[n];
        cout<<"Enter the values in the array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int comparisons=0,swaps=0;
        Solution().selectionSort(arr,n,comparisons,swaps);
        cout<<"The sorted array is : "<<endl;
        for(auto num:arr)
        {
            cout<<num<<" ";
        }
        cout<<"Number of comparisons needed :"<<comparisons<<endl;
        cout<<"Number of swaps needed : "<<swaps<<endl;
    }
    return 0;
}