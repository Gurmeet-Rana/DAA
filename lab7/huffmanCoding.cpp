#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>

using namespace std;

class Node
{
    public : 
        char ch;
        int frq;
        Node *left,*right;
        Node(char ch,int frq)
        {
            this->ch=ch;
            this->frq=frq;
            this->left=NULL;
            this->right=NULL;
        }
        Node(char ch,int frq,Node *l,Node *r)
        {
            this->ch=ch;
            this->frq=frq;
            left=l;
            right=r;
        }
};


class minHeap
{
    public : 
        Node *heap[1000];
        
        int size=0;

        void heapify(int i)
        {
            int smallest=i;
            int left=2*i;
            int right=2*i+1;
            
            if(left<=size && heap[left]->frq<heap[smallest]->frq)
            {
                smallest=left;
            }

            if(right<=size && heap[right]->frq<heap[smallest]->frq)
            {
                smallest=right;
            }

            if(smallest !=i)
            {
                swap(heap[i],heap[smallest]);
                heapify(smallest);
            }
            
        }

        void insert(Node *node)
        {
            size++;
            int i=size;
            heap[size]=node;
            while(i>1 && heap[i]->frq<heap[i/2]->frq)
            {
                swap(heap[i],heap[i/2]);
                i=i/2;
            }
        } 

        Node* extractMin()
        {
            Node * minNode=heap[1];
            heap[1]=heap[size];
            size--;
            heapify(1);
            return minNode; 
        }

};

void encode(Node *root,string str,unordered_map<char,string> &huffmanCode)
{
    if(!root) return ;
    if(!root->left && !root->right)
    {
        huffmanCode[root->ch]=str;
    }
    encode(root->left,str+"0",huffmanCode);
    encode(root->right,str+"1",huffmanCode);
}

void decode(Node *root,string str,unordered_map<char,string> &huffmanCode)
{
    //WE ARE GIVEN THE STRING AND WE HAVE TO TELL THE CORRECPONDING CHARACTER TO THIS STRING

}

void buildHuffMannTree(string &msg)
{

    unordered_map<char,int> frq;
    for(auto ch:msg)
    {
        frq[ch]++;
    }

    minHeap pq;
    for(auto temp:frq)
    {
        pq.insert(new Node(temp.first,temp.second));
    }     

   while(pq.size>1)
   {
       Node *left=pq.extractMin();
       Node *right=pq.extractMin();
       pq.insert(new Node('\0',left->frq+right->frq));  
   }

   Node *root=pq.extractMin();
   unordered_map<char,string> huffmanCode;

   encode(root,"",huffmanCode);

   string encoded;
   for(auto ch:msg)
   {
    encoded+=huffmanCode[ch]+'$';
   }

   string decoded;
   stringstream ss(encoded);
   string str;
   while(getline(ss,str,'$'))
   {

   } 

   
}

int main()
{
    string message;
    getline(cin,message);
    
    buildHuffMannTree(message);
    return 0;
} 