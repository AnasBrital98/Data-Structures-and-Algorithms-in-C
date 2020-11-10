#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

Queue *queue = NULL;

int main(int argc,char** argv)
{
    queue = createQueue(10);
    enQueue(&queue,createNode(1));
    enQueue(&queue,createNode(2));
    enQueue(&queue,createNode(3));
    
    printf("peeked Value : %d \n",peek(&queue));
    printf("deQueue return : %d \n",deQueue(&queue));
    printf("Size of the queue : %d \n",queue->nbr_element);
    return 0;
}
