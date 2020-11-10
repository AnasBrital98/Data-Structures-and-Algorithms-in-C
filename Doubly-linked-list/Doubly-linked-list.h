#ifndef __Doubly_linked_struct__
typedef struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
}Node;

//functions
int isEmpty(Node *node);
void display_forward(Node *head);
void display_backward(Node *head);
void insert_in_the_head(Node **head,int data);
void insert_in_the_last(Node **head,int data);
void insert_Before(Node **head,int x,int data);
void insert_After(Node **head,int x,int data);
void delete(Node **head,int data);
void search(Node **head,int data);
void reverse(Node **head);
#endif