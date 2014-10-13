/**************************************************
   this is the implementation of a singly linked list 
   all necessary classes and functions are defined in this file 
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
        node<T> *next;
    
        node (T x, node<T> *ptr = NULL) {
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
        node<T> * head;
        
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
        
        node<T>* getHead () {return head;}
        void push(T);
        void pop(T);
        void print_List();
        void reverse();
        void recursive_reverse(node<T> *);
        
        
};

/**********************************
   this destructor remove every node
   in the list one by one
***********************************/
template <class T>
LinkedList<T>:: ~LinkedList() {
            
     node<T> *ptr = head;
     node<T> *To_Del = NULL;
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
template <class T>
void LinkedList<T>::push(T n) {
    
    node<T> *ptr = new node<T>(n);
    
    if (head == NULL)
        head = ptr;
    else {
        
        node<T> *prev = head;
        
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
template <class T>
void LinkedList<T>::pop (T v) {
    
     if (head == NULL)
          return;
    
     node<T> *curr;
    
     if (head->value == v) {
          curr = head;
          head = head->next;
          delete curr;
     }
     
     else {
	     node<T> *prev = head;
         curr = head->next;
        
          while (curr != NULL && curr->val != v) {
               prev = curr;
               curr = curr->next;
          }
        
          if (curr != NULL) {
	           prev->next = curr->next;
               delete curr;
          }
        
     }
     
}

// print the values of each node in the list
template <class T>
void LinkedList<T>::print_List() {
	
     node<T> *ptr = head;
     while (ptr != NULL) {
          cout << ptr->val << " ";
          ptr = ptr -> next; 
     }
     cout << endl;
}

template <class T>
node<T>* link(node<T>* frontNodes, node<T> * backNode) {
     	
  	 frontNodes->next = backNode;
	 backNode->next = NULL;
	 return backNode;
}

/***************************************************** 
this function reverses a singly linked list iteratively
by using three pointers, prev, curr and next. at each node
curr, curr point to the previous node, and we will maintain
access to the list with the successor node
*****************************************************/
template <class T>
void LinkedList<T>::reverse() {
   
     if (head == NULL)
   	     return;

     node<T> *prev = NULL, 
             *curr = head, 
             *succ = head->next;
     
     // reverse the direction of the links
     while (succ->next != NULL) {
          curr->next = prev;
          prev = curr;
          curr = succ;
          succ = succ->next;
    }
    // special case where head will point to
    // the last node
          curr->next = prev;
          succ->next = curr;
          head = succ;
}

// reverse the links in a linked list recursively
// the last node will be the first, the first node
// will be last etc...
template <class T>
void LinkedList<T>::recursive_reverse(node<T> * p) {

     // base case, where we must set head to the
     // last node
     if (p->next == NULL) {
          head = p;
          return;
     }
     
     recursive_reverse(p->next);
     
     // have each successive node point
     // to its predecessor, thus reversing the links
     node<T> *q = p->next;
     q->next = p;
     p->next = NULL;
}

int main()
{
     LinkedList<int> l;
   
    // create a linked list
    // with values integer values 0 - 9
     for (int i = 0; i < 10; i ++)
         l.push(i);
     // print the list in order, then reverse, then back again
     l.print_List();
     l.reverse();
     l.print_List();
     l.recursive_reverse(l.getHead());
     l.print_List();
     return 0;
}
