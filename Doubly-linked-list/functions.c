#include<stdio.h>
#include<stdlib.h>
#include "Doubly-linked-list.h"

int isEmpty(Node *node)
{
    return (node == NULL)?1:0;    
}

//display the list forward

void display_forward(Node *head)
{
    if(isEmpty(head))
    {
        printf("The list is empty \n");
        return;
    }
    Node *tmp = head;
    while(tmp!=NULL)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
}

//display the list backward

void display_backward(Node *head)
{
    if(isEmpty(head))
    {
        printf("The list is empty \n");
        return;
    }
    Node *tmp = head;
    while(tmp->next!=NULL)
    {     
        tmp = tmp->next;
    }
    while(tmp != NULL)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->prev;
    }
}

//Insert an item at the head of the list

void insert_in_the_head(Node **head,int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node ->prev = NULL;
    if(isEmpty(*head))
    {
        node->next = NULL;        
        (*head) = node;
        return;
    }
    node->next = (*head);
    (*head)->prev = node;
    (*head) = node;
}

//Insert an item at the end of the list

void insert_in_the_last(Node **head,int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node->next = NULL;    
    if(isEmpty(*head))
    {
        node->prev = NULL;
        (*head) = node ;
        return;
    }
    Node *tmp = (*head);
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
    node->prev = tmp;
}

//Insert an item before the one who contain the value x

void insert_Before(Node **head,int x,int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    if((*head)->value == x)
    {
        node->next = (*head);
        node->prev = NULL;
        (*head)->prev = node;
        (*head) = node;
        return;
    }
    Node *tmp = (*head);      
    while(tmp->next!=NULL)
    {
        if(tmp->next->value == x)
        {
            node->next = tmp->next;
            node->prev = tmp;
            tmp->next->prev = node;            
            tmp->next = node;
            return;
        }
        tmp = tmp->next;
    }
}

//Insert an item after the one who contain the value x

void insert_After(Node **head,int x,int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = data;
    if((*head)->value == x)
    {
        node->prev = (*head);
        node->next = (*head)->next;
        (*head)->next->prev = node;
        (*head)->next = node;
        return;
    }
    Node *tmp = (*head);
    while(tmp->next != NULL)
    {
        if(tmp->value == x)
        {
            node->next = tmp->next;
            node->prev = tmp;
            tmp->next->prev = node;
            tmp->next = node;
            return;            
        }
        tmp = tmp->next;
    }
}

void delete(Node **head,int data)
{
    Node *tmp = (*head);
    while(tmp!= NULL)
    {
        if(tmp->value == data)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;    
            free(tmp);
            return;
        }
        tmp = tmp->next;
    }
    printf("%d does not exist\n",data);
}

void search(Node **head,int data)
{
    Node *tmp = (*head);
    while(tmp!=NULL)
    {
        if(tmp->value == data)
        {
            printf("%d present in the list\n",data);
            return;
        }
        tmp = tmp->next;
    }
    printf("%d does not present in the list\n",data);
}

void reverse(Node **head)
{
    Node *tmp = (*head);
    while (tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    (*head) = tmp;
}