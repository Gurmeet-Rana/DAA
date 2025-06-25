#include<iostream>
using namespace std;

class TreeNode
{
    public : 
        int val;
        TreeNode *left,*right;
        TreeNode(int val)
        {
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }        
}; 

TreeNode* insert(TreeNode *root,int val)
{
     if(!root)
     {
        return new TreeNode(val);
     }
     else if(root->val>val)
     {
        root->left=insert(root->left,val);
     }
     else root->right=insert(root->right,val);

     return root;

}
TreeNode* deleteNode(TreeNode *root,int val)
{
    if(!root) return NULL;
    if(root->val>val)
    {
        root->left=deleteNode(root->left,val);
    } 
    else if(root->val<val)
    {
        root->right=deleteNode(root->right,val);
    }
    else
    {
        if(!root->left)
        {
            return root->right;
        }
        else if(!root->right)
        {
            return root->left;
        }
        
        TreeNode* pre=root->left;
        while(pre->right)
        {
            pre=pre->right;

        }
        root->val=pre->val;
        root->left=deleteNode(root->left,pre->val);
    }

    return root;
}
void inOrder(TreeNode*root)
{
    if(!root) return ;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

int main()
{
    TreeNode *root=NULL;
    
    int choice;
    do
    {
        cout<<"1. INSERT \n 2. DELETE \n 3. PRINT \n 4. EXIT"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
           {
             int val;
            cout<<"Enter value to insert "<<endl;
            cin>>val;
            root=insert(root,val);
            break;
           }
        case 2 : 
           {
             int val;
            cout<<"Enter the value to delete : "<<endl;
            cin>>val;
            root=deleteNode(root,val);
            break;
           }
        case 3 : 
            {
                inOrder(root);
            break;
            }
        
        default:
            break;
        }
    }while(choice!=4);
    return 0;
}