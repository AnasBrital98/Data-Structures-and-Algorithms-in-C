#include<stdio.h>
#include<stdlib.h>
#include "Doubly-linked-list.h"

    Node *head = NULL;

int main(int argc,char** argv)
{    
    insert_in_the_last(&head,1);
    insert_in_the_last(&head,2);
    insert_in_the_last(&head,3);
    search(&head,2);
    delete(&head,2);
    search(&head,2);
    return 0;
}