typedef struct Node{
    int value;
    struct Node *next;
}Node;

//functions
void display_List();
void insert_in_the_head(Node *head,int data);
void insert_in_the_end(Node *head,int data);
void delete_value(Node *head,int data);
void search_value(Node *head,int data);
int isEmpty(Node *node);
void reverse(Node *head);
