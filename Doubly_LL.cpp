#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int key;
    Node *next;
    Node *prev;
    
    
    Node(){
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
        
    }
    Node(int k, int d){
        key = k;
        data = d;
        next = NULL;
        prev = NULL;
    }
    
};
class DoublyLinkedList{
    public:
    Node *head;
    
    DoublyLinkedList(){
       head = NULL; 
    }
    DoublyLinkedList(Node *n){
        head = n;
    }
    //1 Check if node exists//
    Node* checkifnodeexists(int k){
        Node* temp = NULL;
        Node* ptr = head;
        
        while(ptr!=NULL)
        {
            if(ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        
    return temp;
        
        
    }
    
    //2 inserting node at the end//
    void insertnodeatend(Node* n){
        if(checkifnodeexists(n->key) != NULL)
        {
            cout<<"Node Already exists"<<endl;
        }
        else
        {
            if(head == NULL)
            {
                head = n;
                cout<<"Node inserted at the end as head node."<<endl;
            }
            else
            {
                Node* ptr = head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout<<"Node inserted in the end."<<endl; 
            }
        }
    }
    
    //3 Inserting in the start//
    void insertatstart(Node *n){
        if(checkifnodeexists(n->key)!=NULL)
        {
            cout<<"Node already exists."<<endl;
        }
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
            cout<<"Node inserted at the start"<<endl;
        }
    }
    
    //4.Inserting a node in the middle//
    void insertinginmiddle(int k, Node* n){
        Node* ptr = checkifnodeexists(k);
        if(ptr == NULL)
        {
            cout<<"No such Node exists after which you want to add a new node."<<endl;
            
        }
        else
        {
            if (checkifnodeexists(n->key)!=NULL)
            {
                cout<<"Node Already exists with the same key value"<<endl;
                
            }
            else
            {
                Node* nextNode = ptr -> next;
                if(nextNode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout<<"Node Inserted at the End"<<endl;
                }
                else{
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr -> next = n;
                    cout<<"Node Inserted in Between"<<endl;
                }
            }
        }
        
    }
    
    //5 Deleting a node//
    
    void deletenode(int k)
    {
        Node *ptr = checkifnodeexists(k);
        if(ptr == NULL)
        {
            cout<<"No such node exists"<<endl;
            
        }
        else
        {
            if(head->key==k)
            {
                head = head->next;
                cout<<"Node delted(unlinked)"<<endl;
                
            }
            else
            {
                Node *nextNode = ptr ->next;
                Node* prevNode = ptr -> prev;
                if(nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout<<"Node Deleted at the end"<<endl;
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode -> prev = prevNode;
                    cout<<"Node Deleted in Between"<<endl;
                }
            }
        }
    }
    //6 Updating a node//
    void Updating_a_node(int k, int d){
        Node* ptr = checkifnodeexists(k);
        if(ptr!=NULL){
            ptr->data = d;
            cout<<"Node Data Udated successfully"<<endl;
        }
        else
        {
            cout<<"Node doesn't exists."<<endl;
        }
        
    }
    
    //7 display//
    void display(){
        if(head = NULL){
            cout<<"No nodes in DLL."<<endl;
        }
        else{
            cout<<"Doubly Linked list values: ";
            Node *temp = head;
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->data<<") <-->";
                temp = temp->next;
            }
        } 
    }
};
int main(){
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do{
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. insertnodeatend()" << endl;
    cout << "2. insertatstart()" << endl;
    cout << "3. insertinginmiddle()" << endl;
    cout << "4. deleteNode()" << endl;
    cout << "5. updateNode()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    
    switch (option){
    case 0:
      break;
    case 1:
      cout << "insertnodeatend Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.insertnodeatend(n1);
      break;
 
    case 2:
      cout << "insertatstart Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.insertatstart(n1);
      break;
 
    case 3:
      cout << "insertinginmiddle Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      obj.insertinginmiddle(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deletenode(k1);
 
      break;
    case 5:
      cout << "Update Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.Updating_a_node(key1, data1);
 
      break;
    case 6:
      obj.display();
 
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
        }
    }while(option!=0);
    
    return 0;
}
























