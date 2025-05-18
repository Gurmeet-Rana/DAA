/* Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int acitivitySelector(vector<pair<int,int>> &activities,int i,int n,bool& flag)
{
    if(i>=n) return 0;
    int m=i+1;
    if(flag)
    {
        cout<<"Selected Activities are : ";
        flag=!flag;
    }
    cout<<activities[i].first<<" "<<activities[i].second<<endl;
    while(m<n && activities[i].second>activities[m].first)
    {
        m++;
    }
    return 1+acitivitySelector(activities,m,n,flag);
}

int main()
{
    int n;
    cout<<"Enter total number of activities : "<<endl;
    cin>>n; 
    vector<pair<int,int>> activities;
    for(int i=0;i<n;i++)
    {
        int st,end;
        cout<<"Enter the starting time and finishing time of this activity : "<<endl;
        
         
        cin>>st;
        cin>>end;
        activities.push_back({st,end});
    }

    sort(activities.begin(),activities.end(),[](pair<int,int> &a,pair<int,int> &b)
    {
        return a.second<b.second;
    });
    bool flag=true;
    
    int ans=acitivitySelector(activities,0,n,flag);
    cout<<"Number of activities ->"<<ans;

    return 0;
}