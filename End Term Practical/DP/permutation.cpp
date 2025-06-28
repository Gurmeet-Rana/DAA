#include<bits/stdc++.h>

using namespace std ; 
void printPermutations(string str,int i)
{
    if(i>=str.length())
    {
        cout<<str<<" ";
         return ;
    }
    for(int j=i;j<str.length();j++)
    {
        swap(str[i],str[j]);
        printPermutations(str,i+1);
        swap(str[i],str[j]);
    }

}
int main()
{
    string str;
    cout<<"Enter the string : "<<endl;
    cin>>str;
    printPermutations(str,0);
    return 0;
}