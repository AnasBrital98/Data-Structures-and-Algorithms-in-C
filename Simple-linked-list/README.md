### Simply Linked List :

* Node : 
```c
typedef struct Node{
    int value;
    struct Node *next;
}Node;
```

* Functions Prototype :

```c
void display_List(Node *head);
void insert_in_the_head(Node **head,int data);
void insert_in_the_end(Node **head,int data);
void delete_value(Node **head,int data);
void search_value(Node **head,int data);
int isEmpty(Node *node);
void reverse(Node **head);
```
* Implementation :

```c
int isEmpty(Node *node)
{
    if(node == NULL)
        return 1;
    return 0;    
}

void display_List(Node *head)
{    
    if(head == NULL)
    {
        printf("List is Empty");
        return;
    }
    Node *tmp = head;
    while (tmp!=NULL)
    {
        printf("%d \n",tmp->value);
        tmp = tmp->next;
    }
}

void insert_in_the_head(Node **head,int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node->next = (*head);
    (*head) = node;
}

void insert_in_the_end(Node **head,int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node->next = NULL;
    Node *tmp = (*head);
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void delete_value(Node **head,int data)
{    
    Node *tmp1 = (*head);
    if(tmp1->value == data)
    {
        (*head) = tmp1->next;
        free(tmp1);
    }
    
    Node *tmp2 = NULL;
    while(tmp1!=NULL)
    {
        if(tmp1->value == data)
        {
            tmp2->next = tmp1->next;
            free(tmp1);
        }
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }
}

void reverse(Node **head)
{
    Node *previous,*current,*next;
    previous = NULL;
    current = (*head);
    next = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;                
    }
    (*head) = previous;
}

void search_value(Node **head,int data)
{
    if(isEmpty(*head))
    {
        printf("the list is empty\n");
    }
    Node *tmp = (*head);
    while(tmp!=NULL)
    {
        if(tmp->value == data)
        {
            printf("%d is present in the list\n",data);
            return;
        }
        tmp = tmp->next;
    }
    printf("%d is not present in the list\n",data);
}
```

* Testing Simply Linked List :
```c
Node *head = NULL;

int main(int argc,char** argv)
{
    printf("Before delete \n");
    insert_in_the_head(&head,1);
    insert_in_the_head(&head,2);
    insert_in_the_head(&head,3);
    insert_in_the_end(&head,4);
    display_List(head);

    printf("After delete \n");
    delete_value(&head,2);
    display_List(head);
    
    search_value(&head,2);
    search_value(&head,3);
    
    printf("After reversing the list \n");
    reverse(&head);
    display_List(head);
    return 0;
}
```

To Compile The Files Run This Command:

```bash
make makefile out=output_File_Name
```