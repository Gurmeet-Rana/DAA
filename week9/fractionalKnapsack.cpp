/* Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. You have to Design an algorithm and implement it using a program to find the list of the
selected items such that the final selected content has weight w and has maximum value. You can
take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
only a fraction xi of item i, where 0 ≤xi≤ 1. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter the number of items : "<<endl;
    cin>>n;
    vector<pair<double,pair<int,int>>> knapSack(n); 
    for(int i=0;i<n;i++)
    {
        int wt,val;
        cout<<"Enter the weight and value of "<<i<<" th item : "<<endl;
        cin>>wt;
        cin>>val;
         
        knapSack[i]={(double)val/wt,{wt,val}};
    }
    sort(knapSack.begin(),knapSack.end(),[](const pair<double,pair<int,int>> &a,const pair<double,pair<int,int>> &b)
{
    return a.first>b.first;
});
    //YOU HAVE TO SORT BY VAL BY WEIGHT
    double maxVal=0;
    int bagCapacity;
    cout<<"Enter the Maximum Capacity of the bag : "<<endl;
    cin>>bagCapacity;
    for(auto &p:knapSack)
    {
        int wt=p.second.first;
        int val=p.second.second;
        double valPerWt=p.first;
        cout<<wt<<" "<<val<<" "<<valPerWt<<endl;
        if(bagCapacity<wt && bagCapacity>0)
        {
            double newVal=valPerWt*bagCapacity;
            maxVal+=newVal;
            break;
        }
        maxVal+=val;
        bagCapacity-=wt;
    }
    cout<<"Maximum value obtained is : "<<maxVal<<endl;    
    return 0;
}