/* Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N */

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int totalWays(vector<int>&coins,int target,int i)
{
    if(target==0) return 1;
    if(i>=coins.size() || target<0) return 0;   

    return totalWays(coins,target-coins[i],i)+totalWays(coins,target,i+1);
}
int main()
{
    int n;
    cout<<"Enter the number of coins : "<<endl;
    cin>>n;
    vector<int> coins;
    for(int i=0;i<n;i++)
    {
        int coin;
        cout<<"Enter "<<i<<" th coin "<<endl;
        cin>>coin;
        coins.push_back(coin);
    }
    int target;
    cout<<"Enter the target sum : "<<endl;
    cin>>target;
    cout<<totalWays(coins,target,0);
    return 0;
}