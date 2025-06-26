#include <iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class DSU 
{
	public : 
	int n;
	vector<int> parent,rank;
	DSU(int n)
	{
		this->n=n;
		parent.resize(n+1);
		rank.resize(n+1);
		for(int i=0;i<n;i++)
		{
			rank[i]=0;
			parent[i]=i;
		}
	}
	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u]=find(parent[u]);
	}
	void unionByRank(int u,int v)
	{
		int uU=find(u),vV=find(v);
		if(rank[uU]<rank[vV])
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
int MST(vector<vector<int>> &edges,int n,int e)
{
	sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int>&b)
	{
		return a[2]<b[2];
	});
	DSU ds(n);
	int ans=0;
	for(auto &edge:edges)
	{
		int u=edge[0],v=edge[1];
		if(ds.find(u)!=ds.find(v))
		{
			ds.unionByRank(u,v);
			ans+=edge[2];
		}
	}
	return ans;
}
int main() {
	int n,e;
	cin>>n;
	cin>>e;
	vector<vector<int>> edges;
	for(int i=0;i<e;i++)
	{
		int u,v;
		int wt;
		cin>>u;
		cin>>v;
		cin>>wt;
		edges.push_back({u,v,wt});
	}

	cout<<MST(edges,n,e);
	 
}