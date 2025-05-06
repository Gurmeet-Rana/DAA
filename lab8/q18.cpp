/* Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.
Input Format: 
Input will be the graph in the form of adjacency matrix or adjacency list. 
Output Format: 
Output will be 'Yes Cycle Exists' if cycle exists otherwise print 'No Cycle Exists' */


#include<iostream>
#include<vector>
using namespace std;

bool dfsCycle(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &vis,vector<vector<int>> &dfsVis)
{
    vis[i][j]=1;
    dfsVis[i][j]=1;
    for(int col=0;col<matrix[0].size();col++)
    {
        if(matrix[j][col]==1 && !vis[j][col])
        {
            if(dfsCycle(matrix,j,col,vis,dfsVis)) 
            {
                return true;
            }
        }
        else if(dfsVis[j][col]) return true;
    }
    dfsVis[i][j]=0;
    return false;
}

bool isCycle(vector<vector<int>> &matrix)
{
    

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j])
            {
                vector<vector<int>> vis(matrix.size(),vector<int>(matrix.size(),0));
                vector<vector<int>> dfsVis(matrix.size(),vector<int>(matrix.size(),0));
                if(dfsCycle(matrix,i,j,vis,dfsVis)) 
                {                    
                    return true;
                }
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
            cout<<"Is there an edge between "<<i<<" and "<<j<<endl;
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