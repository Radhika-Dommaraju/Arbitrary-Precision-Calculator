#include<stdlib.h>
#include "apc.h"

void insert_last(Dlist **head, Dlist **tail, int res)
{
    Dlist *new;
    new = malloc(sizeof(Dlist));
    new->prev = NULL;
    new->data = res;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
    return;
	}

    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;
return;
}