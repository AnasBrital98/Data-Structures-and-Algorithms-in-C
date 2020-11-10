#ifndef __Queue_
typedef struct Node
{
    int value;
    struct Node *next;
}Node;

typedef struct Queue
{
    unsigned capacity;
    unsigned nbr_element;
    Node *head;
}Queue;

Node* createNode(int value);
Queue* createQueue(unsigned capacity);
void enQueue(Queue **queue,Node *node);
int deQueue(Queue **queue);
int peek(Queue **queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
#endif

