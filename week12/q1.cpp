/* Given two sequences, Design an algorithm and implement it using a program to find the length
of longest subsequence present in both of them. A subsequence is a sequence that appears in the
same relative order, but not necessarily contiguous */


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>

using namespace std;

int solve(string &str1,string &str2,int i,int j)
{
    if(i>=str1.length() || j>=str2.length()) return 0;
    if(str1[i]==str2[j])
    {
        return 1+solve(str1,str2,i+1,j+1);
    }
    return max(solve(str1,str2,i+1,j),solve(str1,str2,i,j+1));
}
int main()
{
    string str1,str2;
    cout<<"Enter first string : "<<endl;
    cin>>str1;
    cout<<"Enter second string : "<<endl;
    cin>>str2;
    cout<<"LCS : "<<solve(str1,str2,0,0);
    return 0;
}