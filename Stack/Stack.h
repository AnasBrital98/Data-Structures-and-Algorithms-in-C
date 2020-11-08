#ifndef __Stack_struct

typedef struct Node
{
    int value;
    struct Node *next;
}Node;

typedef struct Stack
{
    unsigned capacity;
    unsigned nbr_element;
    Node *head;
}Stack;

Stack* createStack(unsigned capacity);
Node* create_Node(int value);
int pop(Stack **stack);
void push(Stack **stack,Node *node);
int peek(Stack **stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
#endif