#include<bits/stdc++.h>
using namespace std ; 
int solve(vector<vector<int>> &activity,int n)
{
    sort(activity.begin(),activity.end(),[](vector<int> &a,vector<int> &b)
{
    return a[1]<b[1];
});
    int last=0;
    int ans=0;
    for(auto &act:activity)
    {
        if(act[0]>last)
        {
            cout<<act[0]<<" "<<act[1]<<endl;
            ans++;
        }
    }
    cout<<"Total activities selected : "<<ans<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of activities : "<<endl;
    cin>>n;
    vector<vector<int>> activities(n);
    for(int i=0;i<n;i++)
    {
        int start,end;
        cout<<"Enter the start time : "<<endl;
        cin>>start;
        cout<<"Enter the end time : "<<endl;
        cin>>end;
        activities[i]={start,end}; 
    }
    return solve(activities,n);
}