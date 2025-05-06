/* Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)
Input Format: 
Input will be the graph in the form of adjacency matrix or adjacency list. 
Output Format: 
Output will be 'Yes Bipartite' if graph is bipartite, otherwise print 'Not Bipartite'. */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int>> &matrix,int V)
{
    vector<int> color(V,0);
    queue<int> q;
    q.push(0);
    vector<int> vis(V+1,0);
    vis[0]=1;
    while(!q.empty())
    {
        int parent=q.front();
        vis[parent]=1;
        for(int i=0;i<=V;i++)
        {
            if(!vis[i] && matrix[parent][i])
            {
                vis[i]=1;
                q.push(i);
            }
            else if(color[i]==color[parent]) return false;
        }
    }
    return true;
}

int main()
{
    int V;
    cout<<"Enter the size of adjacency matrix : "<<endl;
    cin>>V;
    vector<vector<int>> matrix(V,vector<int>(V));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"Is there an edge between "<<i<<" and "<<j<<endl;
            cin>>matrix[i][j];
        }
    }
    cout<<"The graph is : "<<endl;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    if(isBipartite(matrix,V))
    {
        cout<<"Yes , Bipartite !"<<endl;
    }
    else
    {
        cout<<"No , Not Bipartite !"<<endl;
    }
    return 0;
}
