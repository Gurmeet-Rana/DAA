//SPANING TREE IS A TREE WHICH CONTAINS N NODES WITH N-1 NODES WITH NO CYCLE
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

int prims(unordered_map<int,vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int mst=0;
    int n=adj.size();
    vector<int> vis(n,0);
    while(!pq.empty())
    {
        auto temp=pq.top();
        int w=temp.first;
        int v=temp.second;
        pq.pop();
        if(vis[v]) continue;
        vis[v]=1;
        mst+=w;
        for(auto &edge:adj[v])
        {
            if(vis[edge.first])  continue;
            pq.push({edge.second,edge.first});
        }
    }
    return mst;
    
}

int main()
{ 
    int V,E;
    cout<<"Enter the number of vertices : "<<endl;
    cin>>V;
    cout<<"Enter the number of edges : "<<endl;
    cin>>E;

    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter two nodes : "<<endl;
        cin>>u;
        cin>>v;
        int wt;
        cout<<"Enter the weight of this edge : "<<endl;
        cin>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    cout<<"MST WEIGHT : "<<endl;
    cout<<prims(adj)<<endl;


    return 0;
}