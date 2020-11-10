#include<stdlib.h>
#include "Queue.h"

Node* createNode(int value)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}


Queue* createQueue(unsigned capacity)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->nbr_element = 0;
    queue->head = NULL;
    return queue;
}

void enQueue(Queue **queue,Node *node)
{
    if(isEmpty(*queue))
    {
        (*queue)->head = node;
    }else{        
        Node *tmp = (*queue)->head;
        while (tmp->next != NULL )
        {
            tmp = tmp->next;
        }
        tmp->next = node;
    }        
    (*queue)->nbr_element ++;
}

int deQueue(Queue **queue)
{
    if(isEmpty(*queue))
        return -1;
    int value = (*queue)->head->value;
    (*queue)->head = (*queue)->head->next;
    (*queue)->nbr_element --;
    return value;
}

int peek(Queue **queue)
{
    if(isEmpty(*queue))
        return -1;
    return (*queue)->head->value;
}

int isFull(Queue *queue)
{
    return queue->capacity == queue->nbr_element ? 1 : 0;
}

int isEmpty(Queue *queue)
{
    return queue->nbr_element == 0 ? 1 : 0;
}

