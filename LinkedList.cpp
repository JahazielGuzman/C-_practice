/**************************************************
   this is the implementation of a singly linked list 
   all necessary classes are defined in this file 
   for convenience
***************************************************/

#include <iostream>
using namespace std;

/**********************************
   This class defines a node.
   Each node has an integer value and a 
   pointer to the next node
***********************************/
class node {
    public:
        int val;
        node *next;
    
        node (int x, node *ptr = NULL) {
            val = x;
            next = ptr;
        }
};

/****************************************
   This class defines a LinkedList which
   contains int_nodes. It contains a head 
   pointer to the first node in a chain of 
   nodes with integer values.
******************************************/

class LinkedList {
    
    private:
        node * head;
        
    public:
    
        LinkedList() {
        // initialize an empty linked list
            head = NULL;
        }
        
        // destructor
        ~LinkedList(); 
        
        // inline method empty() to
        // check if the list has any
        // nodes
        bool empty() { 
            if (head == NULL) 
                return 1;
            else
                return 0;
        };
        
        node* getHead () {return head;}
        void push(int);
        void pop(int);
        
        
};

/**********************************
   this destructor remove every node
   in the list one by one
***********************************/
LinkedList:: ~LinkedList() {
            
    node *ptr = head;
    node *To_Del = NULL;
    while (ptr != NULL) {
                
        To_Del = ptr;
        ptr = ptr -> next;
            
        delete To_Del;
    }
}

// this method push() takes an integer
// argument and creates a node with this
// value and inserts it in the back
// of the list
void LinkedList::push(int n) {
    
    node *ptr = new node(n);
    
    if (head == NULL)
        head = ptr;
    else {
        
        node *prev = head;
        
        // go to the last node
        while (prev->next != NULL) {
            prev = prev->next;
        }
    
        // put the new node after
        // the last node
        prev->next = ptr;
    }
}

/******************************** 
  remove a node with a particular
  integer value. If it exists remove,
  otherwise if it was never found do
  nothing
********************************/
void LinkedList::pop (int n) {
    
    if (!empty()) {
        node *To_Pop = NULL;
        node *prev = NULL;
        
        // while we are still within the list and
        // we havent found the node to delete
        
        while (To_Pop->val != n && To_Pop != NULL) {
            
            prev = To_Pop;
            To_Pop = To_Pop->next;
        }
        
        // if we found the node
        if (To_Pop != NULL) {
            
            prev->next = To_Pop->next;
            delete To_Pop;
        }
        
    }
    
}

int main()
{
    LinkedList l; 
   
    // create a linked list
    // with values 0 - 9
    for (int i = 0; i < 10; i ++)
        l.push(i);
   
    // print the value of each node
    node *ptr = l.getHead();
    while (ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr -> next; 
    }  

   
    return 0;
}
