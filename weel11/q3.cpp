/* Given a set of elements, you have to partition the set into two subsets such that the sum of
elements in both subsets is same. Design an algorithm and implement it using a program to solve
this problem */
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
bool canDivide(vector<int> &v,int target,int i,vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(i>=v.size() || target<0)
    {
        return false;
    }      
    if(dp[i][target]!=-1) return dp[i][target];
    return canDivide(v,target-v[i],i+1,dp)||canDivide(v,target,i+1,dp); 
}
int main()
{
    int n;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cout<<"Enter "<<i<<" th element : "<<endl;
        cin>>ele;
        v.push_back(ele);
    }
    int sum=accumulate(v.begin(),v.end(),0);
    if(sum%2) 
    {
        cout<<"Not possible to divide the array into two halves ."<<endl;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>((sum/2)+1,-1));
    cout<<"Result : "<<canDivide(v,sum/2,0,dp);
    return 0;
}