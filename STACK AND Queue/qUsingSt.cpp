#include<iostream>
#include<stack>
using namespace std;
class Queue
{
    public : 
        stack<int> st1,st2;
        // m1 : enqueue easy 
        /* void enqueue(int val)
        {
            st1.push(val);
        }
        int deque()
        {
            if(!st1.empty())
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
            else{
                cout<<"Stack is empty !!"<<endl;
                return -1;
            }
        }
        int getFront()
        {
            if(!st1.empty())
            {
                while(st1.size()!=1)
                {
                    st2.push(st1.top());
                    st1.pop();
                } 
                int val=st1.top();
                while(!st2.empty())
                {
                    st1.push(st2.top());
                    st2.pop();
                }
                return val;
            } 
            cout<<"Stack is empty !!"<<endl;
            return -1;
        }
        bool isEmpty()
        {
            return st1.empty();
        } */

        // METHOD 2 : DEQUEUE EASY 
        void enqueue(int val)
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st2.pop();
            }
            st2.push(val);
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }

        } 
        int dequeue()
        {
            if(st1.empty())
            {
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            int val=st1.top();
            st1.pop();            
            return val;
        }
        bool isEmpty()
        {
            return st1.empty();   
        }
        int getFront()
        {
            if(st1.empty())
            {
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            int val;
            while(st1.size()!=1)
            {
                st2.push(st1.top());
                st1.pop();
            }
            val=st1.top();
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            return val;
        }
};
int main()
{
    int choice=-1;
    Queue q ; 
    do
    {
        cout<<"Press : \n1 Enqueue \n2 Dequeue \n3 Get Front \n4 Check Empty \n5 Exit "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            int ele;
            cout<<"Enter value to enqueue : "<<endl;
            cin>>ele;
            q.enqueue(ele);
            break;
        }
            
        case 2 :
            cout<<"Dequeue : "<<q.dequeue()<<endl; 
            break;
        case 3 : 
            cout<<"Front : "<<q.getFront()<<endl;
            break;
        case 4 : 
            cout<<"Empty : "<<q.isEmpty()<<endl;
            break;
        default:
            break;
        }
        /* code */
    } while (choice!=5);
     
    cout<<"EXITING THE PROGRAM..."<<endl;
    return 0;
}