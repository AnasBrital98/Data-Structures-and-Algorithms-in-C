# Stack : LIFO (Last In First Out)

* Node :
```c
typedef struct Node
{
    int value;
    struct Node *next;
}Node;
```

* Stack :
```c
typedef struct Stack
{
    unsigned capacity;
    unsigned nbr_element;
    Node *head;
}Stack;
```

* Functions Prototypes :

```c
Stack* createStack(unsigned capacity);
Node* create_Node(int value);
int pop(Stack **stack);
void push(Stack **stack,Node *node);
int peek(Stack **stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
```

* Functions Implementation :
```c
Stack* createStack(unsigned capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(stack));
    stack->capacity = capacity;
    stack->nbr_element = 0;
    stack->head = NULL;
    return stack;
}

Node* create_Node(int value)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

int pop(Stack **stack)
{
    if(isEmpty(*stack))
        return -1;
    int value  = (*stack)->head->value;
    (*stack)->head = (*stack)->head->next;
    (*stack)->nbr_element --;
    return value;
}

void push(Stack **stack,Node *node)
{
    if(isFull(*stack))
        return;
    node->next = (*stack)->head;
    (*stack)->head = node;
    (*stack)->nbr_element ++;
}

int peek(Stack **stack)
{
    if(isEmpty(*stack))
        return -1;
    return (*stack)->head->value;
}

int isFull(Stack *stack)
{
    return stack->nbr_element == stack->capacity ? 1 : 0 ;
}

int isEmpty(Stack *stack)
{
    return stack->nbr_element == 0 ? 1 : 0 ;
}
```

* Testing The Stack :
```c
Stack *stack = NULL;

int main(int argc,char** argv)
{
    stack = createStack(10);
    push(&stack,create_Node(1));
    push(&stack,create_Node(2));
    push(&stack,create_Node(3));
    push(&stack,create_Node(4));
    push(&stack,create_Node(5));
    push(&stack,create_Node(6));
    push(&stack,create_Node(7));
    push(&stack,create_Node(8));
    push(&stack,create_Node(9));
    push(&stack,create_Node(10));

    printf("popped Value %d \n",pop(&stack));
    printf("popped Value %d \n",pop(&stack));
    printf("popped Value %d \n",pop(&stack));
    printf("Size : %d \n",stack->nbr_element);
    return 0;
}
```

To Compile The Files Run This Command:

```bash
make makefile out=output_File_Name
```