//IT IS A NON COMPARISON BASED SORTING ALGO
//IT SORTS THE ARRAY IN LINEAR TIME COMPLEXITY
//IT EFFICIENTLY WORK IN A RANGE OF [0,K];
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the vector : "<<endl;
    cin>>n;
    int maxElement=INT_MIN;
    int arr[n];
   
    cout<<"Enter the values in the array : "<<endl;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        maxElement=max(maxElement,arr[i]);
    }
    
     
    vector<int> frq(maxElement+1,0);

    for(int i=0;i<n;i++)
    {
        frq[arr[i]]++;
    }

    vector<int> posArr(maxElement+1,0);
    posArr[0]=frq[0];
    for(int i=1;i<=maxElement;i++)
    {
        posArr[i]=posArr[i-1]+frq[i];
    }

    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)  //RIGHT TO LEFT
    {
        int indx=--posArr[arr[i]];
        if(indx!=-1)
        {
            ans[indx]=arr[i];
        }
    }

    cout<<"Sorted array is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;

} 