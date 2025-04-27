#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

void findSum(vector<int> &v,int l,int r,int x,int currSum,unordered_map<int,int> &mp)
{
    if(x==currSum || l>r)
    {
        mp[currSum]++;  
        return ;        
    }
    if(currSum>x)
    {
        return ;
    }
    findSum(v,l+1,r,x,currSum,mp);
    if(currSum<=x-v[l])
    {
        findSum(v,l+1,r,x,currSum+v[l],mp);
    }
}

long long solve(vector<int> &v,int n,int target)
{
    unordered_map<int,int> f1;
    findSum(v,0,n/2-1,target,0,f1);
    unordered_map<int,int> f2;
    findSum(v,n/2,n,target,0,f2);

    long long ans=0;

    for(auto &pair:f1)
    {
        int newT=pair.first;
        if(f2.find(target-newT)!=f2.end())
        {
            ans+=1LL*pair.second*f2[target-newT];
        }
    }

    return ans;

}

int main()
{
    int n,x;
    cout<<"Enter the size of vector : "<<endl;
    cin>>n;
    cout<<"Enter the values in the vector : "<<endl;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    cout<<"Enter the value of sum : "<<endl;
    cin>>x;

    cout<<"The number of subsets that add up to x are : "<<solve(vec,n,x);

    return 0;
}