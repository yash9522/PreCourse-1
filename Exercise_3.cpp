// Time Complexity : O(1) for push() and O(N) for append() and insterAfter()
// Space Complexity : O(1) for all functions

#include <bits/stdc++.h> 
using namespace std; 
  
// A linked list node (changes) 
class Node  
{  
    public: 
    int data;  
    Node *next;    
};  
  
/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */ 
    Node* temp=new Node();
    /* 2. put in the data */  
    temp->data=new_data;
    /* 3. Make next of new node as head */ 
    temp->next=*head_ref;
    /* 4. move the head to point to the new node */
    *head_ref=temp; 
    return; 
}  
  
/* Given a node prev_node, insert a new node after the given  
prev_node */
void insertAfter(Node* prev_node, int new_data)  
{  
    /*1. check if the given prev_node is NULL */ 
    if (!prev_node){
        push (&prev_node, new_data);
        return;
    } 
  
    /* 2. allocate new node */ 
    Node* temp = new Node();
    /* 3. put in the data */ 
    temp->data = new_data;
    /* 4. Make next of new node as next of prev_node */
    temp->next = prev_node->next;
    /* 5. move the next of prev_node as new_node */ 
    prev_node->next = temp;
    return;
}  
  
/* Given a reference (pointer to pointer) to the head  
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* temp = new Node();
    /* 2. put in the data */ 
    temp->data = new_data;
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/  
    temp->next = NULL;
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (!(*head_ref)){
        *head_ref = temp;
        return;
    } 
    /* 5. Else traverse till the last node */
    Node* trav = *head_ref;
    while(trav->next != NULL){
        trav = trav->next;
    }
    /* 6. Change the next of last node */ 
    trav->next = temp;
    return;
}  
  
// This function prints contents of 
// linked list starting from head  
void printList(Node *node)  
{  
    //Your code here
    Node* temp = node;

    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}  
  
/* Driver code*/
int main()  
{  
    Node* head = NULL;   
    append(&head, 6);  
    push(&head, 7);  
    push(&head, 1);    
    append(&head, 4);    
    insertAfter(head->next, 8);  
    cout<<"Created Linked list is: ";  
    printList(head);  
    return 0;  
}  