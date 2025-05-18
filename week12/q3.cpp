/* Given a string of characters, design an algorithm and implement it using a program to print all
possible permutations of the string in lexicographic order */
#include<iostream>

using namespace std;
void printPermutations(string &str,int i)
{
    if(i>=str.length())
    {
        cout<<str<<endl;
        return ;
    }
    for(int j=i;j<str.length();j++)
    {
        if(j!=i && str[i]==str[j]) continue;
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