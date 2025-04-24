#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DisJointSet
{
    public:
    int n;
    vector<int> rank,parent;
    DisJointSet(int n)
    {   
        this->n=n;
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }
    int find(int u)
    {
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    } 
    void unionByRank(int u,int v)
    {
        int uU=find(u);
        int vV=find(v);
        if(uU==vV)
        {
            return;
        }
        else if(rank[uU]<rank[vV])
        {
            parent[uU]=vV;
        }
        else if(rank[vV]<rank[uU])
        {
            parent[vV]=uU;
        }
        else{
            parent[uU]=vV;
            rank[vV]++;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter the number of vertices : "<<endl;
    cin>>n;
    DisJointSet ds(n);
    
    int choice;
    do
    {
        /* code */
        cout<<"Press 1. Find 2. Union 3. EXIT "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int u;
            cout<<"Enter node to find Parent : "<<endl;
            cin>>u;
            cout<<ds.find(u)<<endl;
            /* code */
            break;
        case 2:
            int u,v;
            cout<<"Enter the nodes : "<<endl;
            cin>>u;
            cin>>v;
            ds.unionByRank(u,v);
            break;    
        
        default:
            break;
        }
    } while (choice!=4);
    



    return 0;

}