/**************************************************
   this is the implementation of a singly linked list 
   all necessary classes are defined in this file 
   for convenience
***************************************************/
#include <iostream>
using namespace std;

/**********************************
   This class defines a node.
   Each node has a values of a template
   type thats supports
   comparison operators and a 
   pointer to the next node
***********************************/
template <class T>
class node {
    public:
        T val;
        node *next;
    
        node (T x, node *ptr = NULL) {
            val = x;
            next = ptr;
        }
};

/****************************************
   This class defines a LinkedList which
   contains int_nodes. It contains a head 
   pointer to the first node in a chain of 
   nodes with template values.
******************************************/

template <class T>
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
        void push(T);
        void pop(T);
        void print_List();
        node* reverse(node*);
        
        
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

// this method push() takes a template type
// argument and creates a node with this
// value and inserts it in the back
// of the list
void LinkedList::push(T n) {
    
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
  template value. If it exists remove,
  otherwise if it was never found do
  nothing
********************************/
void LinkedList::pop (T n) {
    
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

// print the values of each node in the list
void LinkedList::print_List() {
	
	
    node *ptr = l.getHead();
    while (ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr -> next; 
    }
}

node* link(node* frontNodes, node * backNode) {
	
	frontNodes->next = backNode;
	backNode->next = NULL;
	return backNode;
}

node* LinkedList::reverse(node * c) {
	
	if (c->next == NULL) {
		head = c;
		return c;
	}
	
	return link(reverse(c->next),c);
}

int main()
{
    LinkedList l;
   
    // create a linked list
    // with values integer values 0 - 9
    for (int i = 0; i < 10; i ++)
        l.push(i);
   
    return 0;
}
