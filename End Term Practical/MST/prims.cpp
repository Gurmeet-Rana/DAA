#include<iostream>
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int MST(unordered_map<int,vector<pair<int,int>>> &adj,int n,int e)
{
	vector<int> vis(n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	 pq.push({0,0});
 
	 int ans=0;
	 while(!pq.empty())
	 {
		auto top=pq.top();
		int wt=top.first;
		int node=top.second;
		pq.pop();
		if(vis[node]) continue;
		ans+=wt;
		vis[node]=1;
		for(auto &adj:adj[node])
		{
			int adjNode=adj.first;
			if(!vis[adjNode])
			{				
				pq.push({adj.second,adjNode});
			}
		}
	 }
	 return ans;
} 
int main() {
	int n,e;
	cin>>n;
	cin>>e;
	unordered_map<int,vector<pair<int,int>>> adj; 
	for(int i=0;i<e;i++)
	{
		int u,v;
		int wt;
		cin>>u;
		cin>>v;
		cin>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}

	cout<<MST(adj,n,e);
	 
}