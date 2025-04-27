/* Given a directed graph with two vertices ( source and destination). Design an algorithm and
implement it using a program to find the weight of the shortest path from source to destination
with exactly k edges on the path
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

/* int dijkstra(unordered_map<int,vector<vector<int>>> &adj,int src,int dst,int k,int V)
{
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,0,src});

    vector<int> dist(V,INT_MAX);
    dist[src]=0;

    int ans=INT_MAX;
    while(!pq.empty())
    {
        auto temp=pq.top();
        pq.pop();
        int cost=temp[0];
        int edge=temp[1];
        int node=temp[2];
        if(edge>k) continue;
        if(node==dst && edge==k) ans=min(ans,cost);
        for(auto &adjPair:adj[node])
        {
            int adjNode=adjPair[0];
            int edgeWt=adjPair[1];
            if(dist[adjNode]>cost+edgeWt)
            {
                dist[adjNode]=cost+edgeWt;
                pq.push({dist[adjNode],edge+1,adjNode});
            }
        }
        
    }
    return ans==INT_MAX?-1:ans;
}
 */

int solve(unordered_map<int,vector<vector<int>>> &adj,int src,int dst,int k)
{
    if(k==0 && src==dst) return 0;
    if(k>0 && src==dst) return INT_MAX;
    
    int ans=INT_MAX;
    for(auto &adjPair:adj[src])
    {
        int temp=solve(adj,adjPair[0],dst,k-1);
        if(temp!=INT_MAX)
        {
            ans=min(ans,adjPair[1]+temp);
        }
    }
    return ans;
}

int main()
{

    int V,E,k;
    cout<<"Enter the number of vertices : "<<endl;
    cin>>V;
    cout<<"Enter the number of edges : "<<endl;
    cin>>E;
    unordered_map<int,vector<vector<int>>> adj;
    for(int i=0;i<E;i++)
    {
        int u,v,wt;
        cout<<"Enter node1 , node 2 and weight :  "<<endl;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    int src,dst;
    cout<<"Enter the source node : "<<endl;
    cin>>src;
    cout<<"Enter the destination node : "<<endl;
    cin>>dst;

    cout<<"Enter maximum number of edge between source and destination : "<<endl;
    cin>>k;

    cout<<"Weight of the shortest path from source to destination with k edges in between : "<<endl;
    /* cout<<dijkstra(adj,src,dst,k,V);    */
    cout<<solve(adj,src,dst,k);

    return 0;

}