#include<stdio.h>
#include "Stack.h"

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