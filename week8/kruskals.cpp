#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class DisJointSet
{
    public: 
        int n;
        vector<int> rank,parent;
        DisJointSet(int n)
        {
            this->n=n;
            rank.resize(n);
            parent.resize(n);
            for(int i=0;i<n;i++)
            {
                rank[i]=0;
                parent[i]=i;
            }
        }
        int findUp(int u)
        {
            if(u==parent[u]) return u;
            return parent[u]=findUp(parent[u]);
        }
        void  unionByRank(int u,int v)
        {
            int uU=findUp(u),vV=findUp(v);
            if(uU==vV) return ;
            else if(rank[uU]<rank[vV])
            {
                parent[uU]=vV;
            }
            else if(rank[uU]>rank[vV])
            {
                parent[vV]=uU;
            }
            else
            {
                parent[uU]=vV;
                rank[vV]++;
            }
        }
};

int kruskals(unordered_map<int,vector<vector<int>>> &adj,int E,int n)
{
    priority_queue<vector<int>> pq;
    for(int i=0;i<E;i++)
    {
        for(auto adjPair:adj[i])
        {
            pq.push({adjPair[1],i,adjPair[0]});
        }
    }

    int mst=0;
    DisJointSet ds(n);
    while (!pq.empty())
    {
        /* code */
        auto temp=pq.top();
        pq.pop();
        int wt=temp[0];
        int u=temp[1];
        int v=temp[2];
        if(ds.findUp(u)!=ds.findUp(v))
        {
            mst+=wt;
            ds.unionByRank(u,v);
        }
    }

      

    return mst;

}

int main()
{

    int V,E;
    cout<<"Enter the number of edges :  "<<endl;
    cin>>E;
    cout<<"Enter the number of vertices : "<<endl;
    cin>>V;
    unordered_map<int,vector<vector<int>>> adj;

    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter two vertices of this edge : "<<endl;
        cin>>u;
        cin>>v;
        int wt; 
        cout<<"Enter the wt of this edge : "<<endl;
        cin>>wt;
        adj[u].push_back({v,wt});
    }

    cout<<"MST WT IS : "<<kruskals(adj,E,V);
    return 0;
}