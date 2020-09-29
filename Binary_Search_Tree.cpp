#include<iostream>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    
    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
        
    }
    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        
    }
};

class BST
{
    public:
    TreeNode* root;
    BST()
    {
        root = NULL;
    }
    bool isEmpty()
    {
        if(root==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void InsertNode(TreeNode* new_node)
    {
        if(root==NULL)
        {
            root = new_node;
            cout<<"Node inserted as a Root Node"<<endl;
        }
        else
        {
            TreeNode* temp = root;
            while(temp!=NULL)
            {
                if(new_node->data == temp->data)
                {
                    cout<<"Node already exists duplicate node not allowed."<<endl;
                    return;
                }
                else if((new_node->data < temp->data)&&(temp->left==NULL))
                {
                    temp->left = new_node;
                    cout<<"Node Inserted as a left node."<<endl;
                    break;
                }
                else if(new_node->data < temp->data)
                {
                    temp = temp->left;
                }
                else if((new_node->data > temp->data)&&(temp->right==NULL))
                {
                    temp->right = new_node;
                    cout<<"Node inserted as a right Node"<<endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void Print2D(TreeNode* new_node)
    {
        if(new_node==root)
        {
            for
        }
    }
    
    

};

int main()
{
    int option, dat;
    BST obj;
    
    do
    {
     cout<<"What option do you want to perform?\nSelect the option. Enter 0 to exit"<<endl;
     cout<<"1.Inserting"<<endl;
     cout<<"2.Print2D"<<endl;
     
     
     cin>>option;
    TreeNode* new_node = new TreeNode();
    switch(option)
     {
        case 0:
        break;
        
        case 1:
        cout<<"Inserting"<<endl;
        cout<<"Enter the data of Node you want to insert in the BST: "<<endl;
        cin>>dat;
        new_node->data = dat;
        obj.InsertNode(new_node);
        cout<<endl;
        break;
        
       
     }
    }
    while(option!=0);
    
    return 0;
    
}
