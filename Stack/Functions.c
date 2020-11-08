#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

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