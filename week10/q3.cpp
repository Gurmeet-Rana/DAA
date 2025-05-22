/* Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array */
#include<iostream>
#include<vector>
using namespace std;
pair<int,int> MooreVotingAlgo(vector<int> &v,int n)
{
    int ans=v.front();
    int freq=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }
        if(freq==0)
        {
            ans=v[i];
        }
    }
    return {ans,freq};
}
int main()
{
    int n;
    cout<<"Enter the size of the vector : "<<endl;
    cin>>n;
    vector<int> v;
    cout<<"Enter the values in the vector : "<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    auto p=MooreVotingAlgo(v,n);
    cout<<"Element - "<<p.first<<" Freq - "<<p.second<<endl;

    return 0;
}