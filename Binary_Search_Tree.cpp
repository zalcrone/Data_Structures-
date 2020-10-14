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
    void PrintPreOrder(TreeNode* r)
    {
        if(r==NULL)
        {
            return;
        }
        cout<<r->data<<" ";
        PrintPreOrder(r->left);
        PrintPreOrder(r->right);
    }
    void PrintInOrder(TreeNode *r)
    {
        if(r==NULL)
        {
            return;
        }
        PrintInOrder(r->left);
        cout<<r->data<<" ";
        PrintInOrder(r->right);
    }
    
    void PrintPostOrder(TreeNode *r)
    {
        if(r==NULL)
        {
            return;
        }
        PrintPostOrder(r->left);
        PrintPostOrder(r->right);
        cout<<r->data<<endl;
        
    }
    
    
    TreeNode* iterativeSearch(int val)
    {
        if(root==NULL)
        {
            return root;
            
        }
        else
        {
            TreeNode* temp = root;
            while(temp!=NULL)
            {
                if(val==temp->data)
                {
                    return temp;
                }
                else if(val<temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
        
    }
    TreeNode* minValueNode(TreeNode* node)
    {
        TreeNode* current = node;
        while(current->left!=NULL)
        {
            current = current->left;  
        }
        return current;
    }
    TreeNode * deleteNode(TreeNode * r, int v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> data) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> data) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> data = temp -> data;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp->data);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
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
     cout<<"2.Printing Pre Order"<<endl;
     cout<<"3.Print In Order"<<endl;
     cout<<"4.Print Post Order"<<endl;
     cout<<"5.IterativeSearch"<<endl;
     cout<<"6.DeleteNode"<<endl;
     
     
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
        
        case 2:
        cout<<"PreOrder representation is:";
        obj.PrintPreOrder(obj.root);
        cout<<endl;
        break;
        
        case 3:
        cout<<"InOrder representation is:";
        obj.PrintInOrder(obj.root);
        cout<<endl;
        break;
        
        case 4:
        cout<<"PostOrder representation is:";
        obj.PrintPostOrder(obj.root);
        cout<<endl;
        break;
        
        case 5:
        cout<<"IterativeSearch operation called"<<endl;
        cout<<"Enter Value of TREE NODE to SEARCH in BST"<<endl;
        cin>>dat;
        new_node = obj.iterativeSearch(dat);
        if(new_node!=NULL)
        {
            cout<<"Value Found"<<endl;
        }
        else
        {
            cout<<"Value Not Found"<<endl;
        }
        break;
        
        
        
        case 6:
        cout<<"DeleteNode operation called"<<endl;
        cout<<"Enter the Value of the Node you want to Delete"<<endl;
        cin>>dat;
        new_node = obj.iterativeSearch(dat);
        if(new_node!=NULL)
        {
            obj.deleteNode(obj.root, dat);
            cout<<"Value Deleted"<<endl;
        }
        else
        {
            cout<<"Value Not Found"<<endl;
        }
        break;
        
        
       default:
       cout<<"Enter Proper Option Number"<<endl;
       break;
     }
   }
    while(option!=0);
    
    return 0;
    
}

