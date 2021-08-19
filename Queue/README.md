# Queue : FiFo (First In First Out)

* Node : 

```c
typedef struct Node
{
    int value;
    struct Node *next;
}Node;
```

* Queue : 

```c
typedef struct Queue
{
    unsigned capacity;
    unsigned nbr_element;
    Node *head;
}Queue;
```

* Functions Prototype : 
```c
Node* createNode(int value);
Queue* createQueue(unsigned capacity);
void enQueue(Queue **queue,Node *node);
int deQueue(Queue **queue);
int peek(Queue **queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
```

* Functions Implementation : 
```c
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
```

* Testing The Queue :
```c
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
```

To Compile The Files Run This Command:

```bash
make makefile out=output_File_Name
```
