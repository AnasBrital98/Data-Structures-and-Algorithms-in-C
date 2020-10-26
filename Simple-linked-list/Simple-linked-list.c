#include<stdio.h>
#include "Simple-linked-list.h"

Node head = NULL;

int main(int argc,char** argv)
{
    printf("Before delete \n");
    insert_in_the_head(&head,1);
    insert_in_the_head(&head,2);
    insert_in_the_head(&head,3);
    insert_in_the_end(&head,4);
    display_List(&head);

    printf("After delete \n");
    delete_value(&head,2);
    display_List(&head);
    
    search_value(&head,2);
    search_value(&head,3);
    
    printf("After reversing the list \n");
    reverse(&head);
    display_List(&head);
    return 0;
}