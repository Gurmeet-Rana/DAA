/* After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results. Can you also implement the same algorithm and verify the correctness of Akshay’s
results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house */
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int N,E;
    cout<<"Enter the number of vertices : "<<endl;
    cin>>N;
    cout<<"Enter the number of edges : "<<endl;
    cin>>E;
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter two vertices : "<<endl;
        
    }
    return 0;
}