/* Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. Design an algorithm and implement it using a program to find  the list of the selected
items such that the final selected content has weight <= w and has maximum value. Here, you
cannot break an item i.e. either pick the complete item or don't pick it. (0-1 property) */

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &wt,vector<int> &val,int i,int n,int W)
{
    if(i>=n || W==0) return 0;
    int take=0;
    if(wt[i]<=W)
    {
        take=val[i]+solve(wt,val,i+1,n,W-wt[i]);
    }
    int skip=solve(wt,val,i+1,n,W);
    return max(take,skip);
}
int main()
{
    int n;
    cout<<"Enter number of items : "<<endl;
    cin>>n;
    vector<int> wt(n),values(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter wt of "<<i+1<<" th item : "<<endl;
        cin>>wt[i];
        cout<<"Enter the value of "<<i+1<<" th item : "<<endl;
        cin>>values[i];
    }
    int W;
    cout<<"Enter the bag capacity : "<<endl;
    cin>>W;
    cout<<solve(wt,values,0,n,W);
    return 0;
}
