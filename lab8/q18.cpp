/* Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.
Input Format: 
Input will be the graph in the form of adjacency matrix or adjacency list. 
Output Format: 
Output will be 'Yes Cycle Exists' if cycle exists otherwise print 'No Cycle Exists' */


#include<iostream>
#include<vector>
using namespace std;

bool dfsCycle(vector<vector<int>> &matrix,int node,vector<int> &vis,vector<int> &dfsVis)
{
    vis[node]=1;
    dfsVis[node]=1;
    for(int neighbor = 0; neighbor < matrix.size(); neighbor++) {
        if(matrix[node][neighbor]) {
            if(!vis[neighbor]) {
                if(dfsCycle(matrix, neighbor, vis, dfsVis))
                    return true;
            } else if(dfsVis[neighbor]) {
                return true;
            }
        }
    }
    dfsVis[node]=0;
    return false;
}

bool isCycle(vector<vector<int>> &matrix)
{
    
    int V=matrix.size(); 

    vector<int> vis(V,0),dfsVis(V,0);
    for(int i=0;i<matrix.size();i++)
    {

        if(!vis[i])
            {
                if(dfsCycle(matrix,i,vis,dfsVis)) 
                {                    
                    return true;
                }
            }
    }
    

    return false;

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
            
            cin>>matrix[i][j];
        }
    }

    if(isCycle(matrix))
    {
        cout<<"Yes , There is a Cycle !!"<<endl;
    }
    else
    {
        cout<<"No , There is not any cycle !!"<<endl;
    }

    return 0;
}



 
/* git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/Gurmeet-Rana/DAA.git
git push -u origin main */