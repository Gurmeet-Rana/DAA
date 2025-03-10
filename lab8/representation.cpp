#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &matrix )
{
    vector<int> vis(matrix.size()+1,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[node][i]==1 && !vis[i])
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }
    cout<<endl<<"BFS HAS BEEN COMPLETED!!"<<endl;
}

void dfs(vector<vector<int>> &matrix,int node,vector<int> &vis)
{
    cout<<node<<" ";
    vis[node]=1;
    for(int i=0;i<matrix.size();i++)
    {
        if(matrix[node][i] && !vis[i])
        {
            dfs(matrix,i,vis);
        }
    }
}

int main()
{
    int V,E;
    cout<<"Enter the number of vertices : "<<endl;
    cin>>V;
    cout<<"Enter the number of edges : "<<endl;
    cin>>E;
    vector<vector<int>> matrix(V+1,vector<int>(V+1,0));
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter node 1 : "<<endl;
        cin>>u;
        cout<<"Enter node 2 : "<<endl;
        cin>>v;
        matrix[u][v]=1;
        matrix[v][u]=1;
    }
    cout<<"The matrix representation of this graph is : "<<endl;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"BFS traversal of this graph is : "<<endl;
    bfs(matrix);

    cout<<"DFS TRAVERSAL OF THIS GRAPH IS : "<<endl;
    vector<int> vis(V,0);
    dfs(matrix,0,vis);

    return 0;
}