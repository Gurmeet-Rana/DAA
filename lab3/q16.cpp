/* Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS) */

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &adj,int node1,int node2,vector<int> &vis,int &value)
{
    vis[node1]=1;
    for(auto adjNode:adj[node1])
    {
        if(!vis[adjNode])
        {
            if(adjNode==node2)
            {
                value=1;
            }
            dfs(adj,adjNode,node2,vis,value);
        }
    }
}

int main()
{
    int testCases=0;
    cout<<"Enter the number of testCases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n,m;
        cout<<"Enter the size of the adjacency matrix : "<<endl;
        cin>>n;
        cin>>m;

        vector<vector<int>> adj(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                int node;
                cout<<"Is there an edges between "<<i<<" and "<<j<<" in the graph ?"<<endl;
                cin>>node;

                adj[i][j]=node;

            }
        }

        cout<<"Adjacency list is : "<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }

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