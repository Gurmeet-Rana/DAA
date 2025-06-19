/* Given an array of nonnegative integers, Design an algorithm and implement it using a program
to find two pairs (a,b) and (c,d) such that a*b = c*d, where a, b, c and d are distinct elements of array */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the vector : "<<endl;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int, pair<int, int>> mp;
    bool found = false;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int product = nums[i] * nums[j];

            if(mp.find(product) != mp.end())
            {
                pair<int, int> prev = mp[product];

               
                if((prev.first != i && prev.second != j) && (prev.second != i && prev.first != j))
                {
                    cout << "Found pairs (" << prev.first << ", " << prev.second << ") and ("
                         << i << ", " << j << ") with same product = " << product << endl;
                    found = true;
                    return 0;   
                }
            }
            else
            {
                mp[product] = {i, j}; 
            }
        }
    }

    if(!found)
        cout << "No pair exists!" << endl;

    return 0;
}
