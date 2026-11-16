#include<stddef.h>
#include<stdlib.h>
#include"apc.h"




int delete_first(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }

    Dlist *temp = *head;

    // Only one node
    if(*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);

    return SUCCESS;
}