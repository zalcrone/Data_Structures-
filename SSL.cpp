
#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;
    
    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }
        
    Node(int k, int d){
            key = k;
            data = d;
            
    }
    
};

class SinglyLinkedList{
    public:
    Node* head;
    
    SinglyLinkedList(){
        head = NULL;
        
    }
    SinglyLinkedList(Node* n){
        head = n;
    }
    
    
    //1.nodeExists
    Node* nodeExists(int k){
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr != NULL)
        {
            if(ptr->key==k){
                temp = ptr;
            }
            else{
                ptr = ptr->next;
            }
        }
        return temp;
    }
    
    
    
    
    //2.Insterting at end
    void InsertAtEnd(Node *n){
        if(nodeExists(n->key)!= NULL)
        {
            cout<<"Node already exists with key value :"<< n->key<<endl;
            
        }
        else{
            if(head == NULL){
                head = n;
                cout<<"Node inserted at end"<<endl;
            }
            else{
                Node* ptr = head;
                while(ptr != NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout<<"Node inserted at end"<<endl;
                  
            }
        }
    }
    //3. Insterting at Beginning
    void InsertAtBeginning(Node *n)
    {
        if(nodeExists(n->key)!= NULL)
        {
            cout<<"Node already exists with key value :"<< n->key<<endl;
            
        }
        else
        {
            n->next = head;
            head = n;
            cout<<"Node inserted at start"<<endl;
        }
    }
    
    
    //4. Inserting a node in the middle
    
    void InsertAtMid(int k, Node *n)
    {
       Node *ptr = nodeExists(k);
       if(ptr == NULL)
       {
           cout<<"No node with key value"<<k<<" exists"<<endl;
       }
       else
       {
            if(nodeExists(n->key)!= NULL)
            {
                cout<<"Node already exists with key value :"<< n->key<<endl;
            }
            else
            {
                n->next = ptr -> next;
                ptr->next = n;
                cout<<"Node Insterted"<<endl;
            }
       }
    }
    
    //5. Deleting a Node
    void DeleteNode(int k)
    {
        if(head == NULL)
        {
            cout<<"List already empty"<<endl;
        }
        else if(head!= NULL)
        {
            if(head->key == k)
            {
                head = head->next;
                cout<<"Node unlinked with key value"<<k<<endl;
            }
            else
            {
               Node *temp;
               Node* ptr1 = head;
               Node* ptr2 = head -> next;
               while(ptr2!=NULL)
               {
                   if(ptr2->key == k)
                   {
                       temp = ptr2;
                       ptr2 = NULL;
                   }
                   else
                   {
                    ptr1 = ptr1 ->next;
                    ptr2 = ptr2 -> next;
                   }
               }
               if(temp!= NULL)
               {
                   ptr1 -> next = temp -> next;
                   cout<<"Node Unlinked with key value"<<k<<endl;
               }
               else
               {
                   cout<<"Node doesn't exist with given value"<<endl;
                   
               }
               
            }
        }
    }
    
    //6. Update a Node
    void UpdateNode(int k, int d)
    {
        Node* ptr = nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data = d;
            cout<<"Node updated successfully"<<endl;
        }
        else
        {
            cout<<"Node doesn't exist with key value"<<k<<endl;
        }
    }
    
    //7. Display List
    void Display()
    {
        if(head == NULL)
        {
            cout<<"No nodes in singly linked lists"<<endl;
        }
        else
        {
            cout<<"Singly list values: ";
            Node* temp = head;
            
            while(temp!= NULL)
            {
                cout<<"("<<temp->key<<", "<<temp->data<<") -->";
                temp = temp->next;
            }
        }
    }
    
    
    
    
};

int main()
{
   SinglyLinkedList s;
   int option;
   int key1, k1, data1;
   do
   {
       cout<<"Select option number:(Enter 0 to exit)"<<endl;
       cout<<"1.Inserting at end()"<<endl;
       cout<<"2.Inserting at Beginning()"<<endl;
       cout<<"3.Inserting in middle()"<<endl;
       cout<<"4.Deleting Node()"<<endl;
       cout<<"5.Updating a Node()"<<endl;
       cout<<"6.Displaying A Node()"<<endl;
       cout<<"7.Clear Screen()"<<endl;
       cout<<"Your input: ";
       cin>>option;
       Node *n1 = new Node();
       
       switch(option)
       {
           case 0:
                break;
           
           case 1:
                cout<<"Insert at end operation \nEnter key and data of the Node to be Appended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.InsertAtEnd(n1);
                break;
           
           case 2:
                cout<<"Insert at Beginning operation \nEnter key and data of the Node to be Prepended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.InsertAtBeginning(n1);
                break;
           
           case 3:
                cout<<"Insert at mid operation \nEnter key and data after which you want to insert this new node:"<<endl;
                cin>>k1;
                cout<<"Insert key and data of the new node first: "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.InsertAtMid(k1, n1);
                break;
           
           case 4:
                cout<<"Delete a Node operation - \nEnter key of the node to be deleted: "<<endl;
                cin>>k1;
                s.DeleteNode(k1);
                break;
           
           case 5:
                cout<<"Updating node operation \nEnter key and New data to be updated"<<endl;
                cin>>key1;
                cin>>data1;
                s.UpdateNode(key1, data1);
                break;
           
           case 6:
                s.Display();
                break;
           
           case 7:
                system("cls");
           
           default:
                cout<<"Enter proper option number"<<endl;
           
       }
       
   }while(option!=0);

    return 0;
}


