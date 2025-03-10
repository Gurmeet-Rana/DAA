/* Given an array of nonnegative integers, design an algorithm and a program to count the number
 of pairs of integers such that their difference is equal to a given key, K.  */

 
 #include<iostream>
 #include<vector> 
 #include<unordered_map>
 using namespace std;
 class Solution
 {
    public :
        int countPairs(vector<int> &v,int n,int k)
        {
            unordered_map<int,int> mp;
            for(auto i:v) mp[i]++;
            int pairs=0;
            for(auto num:v)
            {
                pairs+=mp[num+k];
            }
            return pairs;
        }
 };
 int main()
 {
    int testCases;
    cout<<"Enter the number of testCases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n;
        cout<<"Enter the size of vector : "<<endl;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int k;
        cout<<"Enter the value of k :"<<endl;
        cin>>k;
        int pairs=Solution().countPairs(arr,n,k);
        cout<<"The number of pairs with difference "<<k<<" is : "<<pairs<<endl;
    }
    return 0;
 }