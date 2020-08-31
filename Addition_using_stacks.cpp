#include <iostream>
using namespace std;

template <class tp>
class stacks
{   struct node
{
  public: tp data;
          node* next;
};
    private: node* head;
    public: 
    tp n1;
    stacks()
    {
      head=NULL;
    }
    void push(int x)
   {
       
     node* temp=new node;
     temp->data=x;
     temp->next=NULL;
     if(head==NULL)
     {
         head=temp;
         temp=NULL;
     }
     else
     {
         temp->next=head;
         head=temp;
     }
   }
   void pop()
   {
       if(head==NULL)
               {
                   cout<<"Stack is empty. "<<"Enter another operation"<<endl;
               }
               else
               {   cout<<"Poping top element from the stack"<<endl;
                   node* ptr=new node;
                   ptr=head;
                   head=ptr->next;
                   ptr=NULL;
               }
   }
     void add(stacks<tp> obj1,stacks<tp> obj2)
     {
         int remainder=0;
         int a,b,c;
         node* ptr1=new node;
         ptr1=obj1.head;
         node* ptr2=new node;
         ptr2=obj2.head;
         while(ptr1!=NULL && ptr2!=NULL)
         {  
             b= ptr1 -> data + ptr2 -> data;
             c = b % 10;
             a = c + remainder;
             remainder = (b)/10;
             push(a);
             ptr1=ptr1->next;
             ptr2=ptr2->next;
         }
         if(ptr1==NULL)
         {
             while(ptr2!=NULL)
             {
                 push(ptr2->data+remainder);
                 remainder=remainder/10;
                 ptr2=ptr2->next;
             }
         }
         else
         if(ptr2==NULL)
         {
             while(ptr1!=NULL)
             {
                 
                     push(ptr1->data+remainder);
                     remainder=remainder/10;
                     ptr1=ptr1->next;
                 
             }
         }
            display();
     }
     void display()
     {
        node* ptr=new node;
        ptr=head;
        if(head==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {   cout<<"RESULT IS:"<<endl;
        while(ptr!=NULL)
         {
            cout<<ptr->data<<"";
            ptr=ptr->next;
        }
        }
        cout<<endl<<endl<<endl;
        
     }
};
int main()
{   int n=0, n1 ,n2 ,rem, Reversed_Number_1=0 ,rem1=0 , Reversed_Number_2=0;
   stacks<int> obj, obj1 ,obj2 ,obj3;
    int option,key=1;
   
 do
 {  
    cout << "What operation do you want to perform?" <<endl
     <<"Select Option number." << endl;
    cout<<"Press 1 for addition operation."<<endl;
    cout<<"Press 0 to exit"<<endl;
    cin>>option;
    switch(option)
    {
        case 0: 
            key=0;
            break;
    
        case 1:            
            cout<<"Input 1st integer Number: "<<endl;
            cin>>n1;
            while(n1 != 0) {
            rem = n1%10;
            Reversed_Number_1 = Reversed_Number_1*10 + rem;
            n1 /= 10;
            }
            while(Reversed_Number_1!=0)
            {     
                obj1.push(Reversed_Number_1 % 10);
                Reversed_Number_1 = Reversed_Number_1 / 10;
            }
  
           cout<<"Input 2nd integer Number: "<<endl;
           cin>>n2;
           while(n2 != 0)
           {
                rem1 = n2 % 10;
                Reversed_Number_2 = Reversed_Number_2*10 + rem1;
                n2 /= 10;
           }
           while(Reversed_Number_2 != 0)
           {
              obj2.push(Reversed_Number_2 % 10);
              Reversed_Number_2 = Reversed_Number_2/10;
           }
  
           obj3.add(obj1,obj2);
           break;
           
           
           default:
               cout<<"Invalid input"<<endl<<"Try adding a proper integer number."<<endl;
        
    }
 }while(option != 0);
    return 0;
}
