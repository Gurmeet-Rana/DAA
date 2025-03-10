#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v,int i,int n)
{
    int maxIndex=i;
    int leftChild=2*i,rightChild=2*i+1;

    if(leftChild<=n && v[leftChild]>v[maxIndex])
    {
        maxIndex=leftChild;
    }
    
    if(rightChild<=n && v[rightChild]>v[maxIndex])
    {
        maxIndex=rightChild;
    }

    if(maxIndex!=i)
    {
        swap(v[maxIndex],v[i]);
        heapify(v,maxIndex,n);
    }
    
    
}

void heapSort(vector<int> &v,int low,int high)
{
    //FIRSTLY BUILD THE HEAP 
    for(int i=high/2;i>=1;i--)
    {
        heapify(v,i,high);
    }

    //START SORTING
    for(int i=high;i>=1;i--)
    {
        swap(v[i],v[1]);

        heapify(v,1,i-1);

    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;

    vector<int> v(n+1);

    cout<<"Enter the values in the array : "<<endl;

    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }

    heapSort(v,1,n);
    
    cout<<"The Sorted array is : "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl<<"EXITING THE PROGRAM...."<<endl;
    return 0;

}