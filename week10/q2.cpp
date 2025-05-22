/* Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
deadline associated with it. You have to design an algorithm and implement it using a program to
find maximum number of tasks that can be completed without crossing their deadlines and also
find list of selected tasks. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of tasks : "<<endl;
    cin>> n;
    vector<pair<int,int>> acitivites(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the time and deadline of the "<<i<<" th task ."<<endl;
        pair<int,int> p;
        cin>>p.first;
        cin>>p.second;
        acitivites[i]=p;
    }

    sort(acitivites.begin(),acitivites.end(),[](const pair<int,int> &p1,const pair<int,int> &p2)
    {
        
        return p1.second==p2.second?p1.first<p2.first:p1.second<p2.second;
    });

    int i=0;
    int ans=0;

    int time=0;
    vector<int> selected;
    while(i<n)
    {
        if(time+acitivites[i].first<acitivites[i].second)
        {
            ans++;
            time+=acitivites[i].first;
            selected.push_back(i);
        }
        i++;
    }
    cout<<"Output : "<<ans<<endl;

    return 0;

}