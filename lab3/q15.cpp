/* You have been given two sorted integer arrays of size m and n.  Design an algorithm and
implement it using a program  to find list of elements which are common to both. (Time
Complexity = O(m+n) */

#include<iostream>
#include<vector>
using namespace std;

vector<int> commonElements(vector<int> &v1,int n1,vector<int> &v2,int n2)
{
    vector<int> commons;

    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(v1[i]==v2[j])
        {
            commons.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return commons; 
}

int main()
{
    int testCases=0;
    cout<<"Enter the number of test Cases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
        int n1,n2;
        cout<<"Enter the size of the list 1 : "<<endl;
        cin>>n1;
        vector<int> list1,list2;

        cout<<"Enter the elements in the list 1 : "<<endl;
        for(int i=0;i<n1;i++)
        {
            int ele;
            cin>>ele;
            list1.push_back(ele);
        }
        cout<<"Enter the size of the list 2 : "<<endl;
        cin>>n2;

        cout<<"Enter the elements in the list 2 : "<<endl;
        for(int i=0;i<n2;i++)
        {
            int ele;
            cin>>ele;
            list2.push_back(ele);
        }

       vector<int> commons= commonElements(list1,n1,list2,n2);
        if(commons.empty())
        {
            cout<<"No common element is present !!"<<endl;
        }        
        else
        {
            cout<<"Common elements are : "<<endl;
            for(auto c:commons) cout<<c<<" ";
            cout<<endl; 
        }
    }

    cout<<"EXITING THE PROGRAM......."<<endl;
    return 0;

}