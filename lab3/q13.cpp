/* Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. */


#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int testCases=0;
    cout<<"Enter the number of testCases : "<<endl;
    cin>>testCases;
    while(testCases--)
    {
               
        vector<char> v(26,0);
        
        int n;
        cout<<"Enter the number of letters you want to enter : "<<endl;
        cin>>n;
        while(n--)
        {
            char ch;
            cin>>ch;
            v[ch-'a']++;
        }
        
        int maxFrq=0;
        char character='$';
        for(int i=0;i<26;i++)
        {
            if(v[i]>maxFrq)
            {
                maxFrq=v[i];
                character='a'+i;
            }
        }

        if(character=='$')
        {
            cout<<"No character is present ."<<endl;
        }
        else
        {
            cout<<character<<" is the most frequent character with frequency : "<<maxFrq<<endl;
        }


    }

    cout<<"Exiting the program...."<<endl;

    return 0;
}