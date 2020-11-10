 #ifndef __Simple__linked_struct_

typedef struct Node{
    int value;
    struct Node *next;
}Node;

//functions
void display_List(Node *head);
void insert_in_the_head(Node **head,int data);
void insert_in_the_end(Node **head,int data);
void delete_value(Node **head,int data);
void search_value(Node **head,int data);
int isEmpty(Node *node);
void reverse(Node **head);

#endif