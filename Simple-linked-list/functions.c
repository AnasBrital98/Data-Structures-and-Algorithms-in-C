#include "Simple-linked-list.h"
#include<stdio.h>
#include<stdlib.h>

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