#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the size of the arrays :  "<<endl;
    cin>>n;
    cin>>m;
    vector<int> arr1(n),arr2(n);
    cout<<"Enter the values in the first array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the values in the second array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    
    return 0;
}