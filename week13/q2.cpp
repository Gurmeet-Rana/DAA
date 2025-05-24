/* Given an array of integers of size n, design an algorithm and write a program to check whether
this array contains duplicate within a small window of size k < n */

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of values : "<<endl;
    cin>>n;
    int k;
    cout<<"Enter the size of window : "<<endl;
    cin>>k;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int ele;
        cout<<"Enter "<<i<<" th element : ";
        cin>>ele;
        nums.push_back(ele);
    }

    for(int i=0;i<=n-k;i++)
    {
        unordered_set<int> vis;
        for(int j=i;j<i+k;j++)
        {
            if(vis.count(nums[j]))
            {
                cout<<"Found Duplicate in window starting at "<<i<<endl;
                return 0;
            }
            vis.insert(nums[j]);
        }
    }
    cout<<"No Duplicate is found in window size of : "<<k<<endl;
    return 0;
}