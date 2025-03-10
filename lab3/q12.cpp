/* Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n)) */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findKthSmallest(vector<int> &arr,int k,int n)
{
    if(k>n)
    {
        cout<<"Kth Smallest Doesn't Exists !"<<endl;
        return -1;
    }
    priority_queue<int> maxHeap;
    for(auto num:arr)
    {
        maxHeap.push(num);
        if(maxHeap.size()>k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int findKthLargest(vector<int> &arr,int k,int n)
{
    if(k>n)
    {
        cout<<k<<" th Largest Element doesn't exists !!"<<endl;
        return -1;
    }
    priority_queue<int,vector<int> ,greater<int>> minHeap;
    for(int i=0;i<n;i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size()>k)
        {
            minHeap.pop();
        }
    }
    return minHeap.top();
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
        vector<int> v(n,0);
        cout<<"Enter the values in the vector : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int choice=0;
        do
        {
            cout<<"Press : \n1 To find kth Smallest in the array \n2 To find kth largest in the array \n3 Exit"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
                {
                    int k;
                    cout<<"Enter the value of k to find kth smallest : "<<endl;
                    cin>>k;
                    cout<<k<<" th smallest is : "<<findKthSmallest(v,k,n)<<endl;
                }
                break;
            case 2:
                {
                    int k;
                    cout<<"Enter the value of k to find kth largest : "<<endl;
                    cin>>k;
                    cout<<k<<" th largest is : "<<findKthLargest(v,k,n)<<endl;
                }    
            
            default:
                break;
            }
        } while (choice!=3);

        
        cout<<"Exiting the program......"<<endl;
    }
    return 0;
}