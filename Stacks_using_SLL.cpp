#include<iostream>
 
using namespace std;
 
class node {
  public:
    int key;
  int data;
  node * next;
 
  node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  node(int k, int d) {
    key = k;
    data = d;
    next = NULL;
  }
};
 
class stack {
  public:
    node * top;
 
  stack() {
    top = NULL;
  }
 
  bool isempty() {
    if (top == NULL) {
      return true;
    } else {
      return false;
    }
  }
  bool checkifnodeexist(node * n) {
    node * temp = top;
    bool exist = false;
    while (temp != NULL) {
      if (temp -> key == n -> key) {
        exist = true;
        break;
      }
      temp = temp -> next;
    }
    return exist;
  }
 
  void push(node * n) {
    if (top == NULL) {
      top = n;
      cout << "Node  pushed successfully" << endl;
    } else if (checkifnodeexist(n)) {
      cout << "Node already exist"<< endl;
    } else {
      node * temp = top;
      top = n;
      n -> next = temp;
      cout << "Node  pushed successfully" << endl;
    }
 
  }
 
  node * pop() {
    node * temp = NULL;
    if (isempty()) {
      cout << "stack underflow" << endl;
      return temp;
    } else {
      temp = top;
      top = top -> next;
      return temp;
    }
  }
  node * peek() {
    if (isempty()) {
      cout << "stack underflow" << endl;
      return NULL;
    } else {
      return top;
    }
  }
  int count() {
    int count = 0;
    node * temp = top;
    while (temp != NULL) {
      count++;
      temp = temp -> next;
    }
    return count;
  }
  void display() {
    cout << "All values in the Stack are :" << endl;
    node * temp = top;
    while (temp != NULL) {
      cout << "(" << temp -> key << "," << temp -> data << ")" << " -> " <<
        endl;
      temp = temp -> next;
    }
    //cout<< "Total no of Nodes in the stack :" <<count()
    //<<endl;
    cout << endl;
  }
 
};
 
int main() {
  stack s1;
  int option, key, data;
 
  do {
    cout << "What operation do you want to perform?" <<
      "Select Option number. Enter 0 to exit." << endl;
    cout << "1. push" << endl;
    cout << "2. pop" << endl;
    cout << "3. isempty" << endl;
    cout << "4. peek" << endl;
    cout << "5. count" << endl;
    cout << "6. display" << endl;
    cout << "7. Clear Screen" << endl << endl;
    cin >> option;
 
    //Node n1 = new Node();
    node * new_node = new node();
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter KEY and VALUE of NODE to push in the stack" <<
        endl;
      cin >> key;
      cin >> data;
      new_node -> key = key;
      new_node -> data = data;
      s1.push(new_node);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << endl;
      new_node = s1.pop();
      cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")";
      delete new_node;
      cout << endl;
 
      break;
    case 3:
      if (s1.isempty())
        cout << "stack is empty" << endl;
      else
        cout << "stack is not empty" << endl;
      break;
    case 4:
      if (s1.isempty()) {
        cout << "stack is empty" << endl;
      } else {
        cout << "peek Function Called : " << endl;
        new_node = s1.peek();
        cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")" <<
          endl;
      }
      break;
    case 5:
      cout << "Count Function Called: " << endl;
      cout << "No of nodes in the Stack: " << s1.count() << endl;
      break;
 
    case 6:
      cout << "display Function Called - " << endl;
      s1.display();
      cout << endl;
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}
