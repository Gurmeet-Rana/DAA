/* Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. Design an algorithm and implement it using a program to find  the list of the selected
items such that the final selected content has weight <= w and has maximum value. Here, you
cannot break an item i.e. either pick the complete item or don't pick it. (0-1 property) */

#include<iostream>
#include<vector>
using namespace std;

int tabulation(vector<int> &wt,vector<int> &val,int &W)
{
    int n=wt.size();
    vector<vector<int>> t(n+1,vector<int>(W+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=W;j++)
        {
            int w=wt[i];
            int v=val[i];
            if(w<=j)
            {
                t[i][j]=max(v+t[i+1][j-w],t[i+1][j]);
            }
            else
            {
                t[i][j]=t[i+1][j];
            }
        }
    }
    return t[0][0];
}



vector<vector<int>> dp;
int solve(vector<int> &wt,vector<int> &val,int i,int n,int W)
{
    if(i>=n || W==0) return 0;
    if(dp[i][W]!=-1) return dp[i][W];
    int take=0;
    if(wt[i]<=W)
    {
        take=val[i]+solve(wt,val,i+1,n,W-wt[i]);
    }
    int skip=solve(wt,val,i+1,n,W);
    return dp[i][W]=max(take,skip);
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
    dp.resize(n+1,vector<int>(W+1,-1));
    cout<<solve(wt,values,0,n,W)<<endl;

    cout<<tabulation(wt,values,W);


    return 0;
}
