/* Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.
Input Format: 
Input will be the graph in the form of adjacency matrix or adjacency list. 
Output Format: 
Output will be 'Yes Cycle Exists' if cycle exists otherwise print 'No Cycle Exists' */


#include<iostream>
#include<vector>
using namespace std;


bool isCycle(vector<vector<int>> &matrix)
{
    vector<int> vis(matrix.size(),0);
    vector<int> dfsVis(matrix.size(),0);
}


int main()
{
    int V,E;
    cout<<"Enter the number of Vertices : "<<endl;
    cin>>V;
    cout<<"Enter the number of Edges : "<<endl;
    cin>>E;
    vector<vector<int>> matrix(V,vector<int>(E,0));
    for(int i=1;i<=E;i++)
    {
        int n1,n2;
        cout<<"Enter first node : "<<endl;
        cin>>n1;
        cout<<"Enter second node : "<<endl;
        cin>>n2;
        matrix[n1][n2]=1;
        matrix[n2][n1]=1;
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