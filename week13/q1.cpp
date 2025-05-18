/* Given an array of characters, you have to find distinct characters from this array. Design an
algorithm and implement it using a program  to solve this problem using hashing. (Time
Complexity = O(n) */
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<char> st;
    char ch;
    do
    {
        cout<<"Enter a character . Enter @ to exit";
        cin>>ch;
        if(ch!='@')
        {
            st.insert(ch);
        }
        /* code */
    } while (ch!='@');

    for(auto it=st.begin();it!=st.end();++it) cout<<*it<<" ";

    
    return 0;
}