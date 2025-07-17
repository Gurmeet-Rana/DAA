#include<iostream>
#include<queue>
using namespace std; 
class Stack 
{
    public : 
        queue<int> q1,q2;
        void push(int val)
        {
            // 1 2 3 
            q2.push(val);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
        int pop()
        {
            if(q1.empty())
            {
                cout<<"Stack is empty !"<<endl;
                return -1;
            }
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            } 
            int val=q2.front();
            q2.pop();            
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            return val;
        }
        bool isEmpty()
        {
            return q1.empty();
        }
        int getTop()
        {
            if(q1.empty())
            {
                cout<<"Stack is empty !"<<endl;
                return -1;
            }
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            } 
            int val=q2.front();                 
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            return val;
        }
};
int main ()
{
    int choice;
    Stack st;
    do{
        cout<<"Press :\n1. to Push val \n2. to pop \n3. Get Top\n4. Check Empty \n5. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            {
                int val;
                cout<<"Enter value to push : "<<endl;
                cin>>val;
                st.push(val);
                break;
            }
        case 2:
            cout<<st.pop()<<endl;
            break;
        case 3: 
            cout<<st.getTop()<<endl;
            break;
        case 4: 
           cout<<"Check empty : "<<st.isEmpty()<<endl;
           break;
        
        default:
            break;
        }
    }while(choice!=5);
    cout<<"---EXITING THE PROGRAM---"<<endl;
    return 0;
}