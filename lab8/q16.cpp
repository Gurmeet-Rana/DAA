/* Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS) */

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &adj,int node1,int node2,vector<int> &vis,int &value)
{
    vis[node1]=1;
    if(node1==node2)
    {
        value=1;
        return ;
    }
    for(int adjNode=0;adjNode<adj[node1].size();adjNode++)
    {
        if(adj[node1][adjNode] && !vis[adjNode])
        {
            
            dfs(adj,adjNode,node2,vis,value);
            if(value) return;
        }
    }
}

int main()
{
    int n,m;
        cout<<"Enter the size of the adjacency matrix : "<<endl;
        cin>>n;
        cin>>m;

        vector<vector<int>> adj(n,vector<int>(m,0));

        cout<<"Enter values in the adjacent matrix : "<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {                                
                cin>>adj[i][j];
            }
        }

        cout<<"Adjacency Matrix is : "<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }


    int testCases=0;
    cout<<"Enter the number of testCases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        
        int node1,node2;
        cout<<"Enter first node : "<<endl;
        cin>>node1;
        cout<<"Enter second node : "<<endl;
        cin>>node2;

        vector<int> vis(n,0);

        int value=0;
        dfs(adj,node1,node2,vis,value);

        if(value)
        {
            cout<<"There exists a path between "<<node1<<" and "<<node2<<endl;
        }
        else{
            cout<<"There doesnot exists a path between "<<node1<<" and "<<node2<<endl;
        }


    }

    cout<<"EXITING THE PROGRAM......"<<endl;
    return 0;
}

/*
 A GRAPH IS A NON-LINEAR DATA STRUCTURE WHICH IS A COMBINATION OF NODES / VERTICES AND EDGES .
 
 OR A TREE WHICH CONTAINS CYCLE IS A GRAPH . EVERY TREE IS A GRAPH BUT NOT VICE VERSA.

    DEGREE OF A GRAPH : 2*E
    PATH : COLLECTION OF NODES OR VERTICES IN WHICH THE ADJACENT TWO NODES ARE DIRECTLY CONNECTED TO EACH OTHER . IN A PATH NO TWO VERTICES REPEAT .   

 TYPES 

 1. UNDIRECTED GRAPH (BIDIRECTIONAL)
 2. DIRECTED GRAPH 
 3. WEIGHTED GRAPH 
 */ 