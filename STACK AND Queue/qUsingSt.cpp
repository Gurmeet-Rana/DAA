#include<iostream>
#include<stack>
using namespace std;
class Queue
{
    public : 
        stack<int> st1,st2;
        // m1 : enqueue easy 
        void enqueue(int val)
        {
            st1.push(val);
        }
        int deque()
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int val=st2.top();
            st2.pop();
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            return val;
        }
        bool isEmpty()
        {
            return st1.empty();
        }
};
int main()
{
    int choice=-1;
    do
    {
        cout<<"Press : \n1 "
        /* code */
    } while (choice!=4);
     
    
    return 0;
}