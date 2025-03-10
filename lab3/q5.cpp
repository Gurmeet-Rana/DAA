/* Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. */

#include<iostream>
#include<vector> 
using namespace std;
class Solution
{
    int searchElement(int arr[],int st,int end,int val)
    {
        int left=st,right=end-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]==val) return mid;
            else if(arr[mid]<val)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return -1;
    }
    public:
        vector<int> findIndices(int arr[],int n)
        {
            vector<int> indices(3,-1);
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int target=arr[i]+arr[j];
                    int indx=searchElement(arr,j,n,target);
                    if(indx>j)
                    {
                        indices[0]=i;
                        indices[1]=j;
                        indices[2]=indx;
                        return indices;
                    }
                }
            }
            return indices;
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
        cout<<"Enter the size of the array : "<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the values in the array : "<<endl;
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> indices=obj.findIndices(arr,n);
        cout<<"i = "<<indices[0]<<" , j = "<<indices[1]<<" , k = "<<indices[2]<<endl;        
    }
    return 0;
} 