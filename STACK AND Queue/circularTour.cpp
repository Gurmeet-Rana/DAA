#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public :
        static int circularTour(vector<pair<int,int>>& stations)
        {
            int n=stations.size();
            int fuel=0;
            for(int start=0;start<n;start++)
            {
                int extra=stations[start].second-stations[start].first;
                int j=start;
                while(extra>0)
                {
                    extra+=stations[j].second-stations[j].first;
                    j=(j+1)%n;
                    if(j==start) return true;
                }
            }
            return false;
        }
};
int main()
{
    int n;
    cout<<"Enter the number of stations : "<<endl;
    cin>>n;
    vector<pair<int,int>> stations;
    for(int i=0;i<n;i++)
    {
        int cost,fuel;
        cin>>cost>>fuel;
        stations.push_back({fuel,cost});
    }
    cout<<"Number of stations : "<<Solution::circularTour(stations)<<endl;
    return 0;
}
